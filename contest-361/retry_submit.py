#!/usr/bin/env python3
"""Final re-submit of remaining failed problems."""
import json, subprocess, sys, time, os, re

BASE_URL = "http://xmuoj.com"
CONTEST_ID = 361
PASSWORD = "ilovexmu"
COOKIE_FILE = "/tmp/xmuoj_cookies.txt"
SOLUTION_DIR = "/home/wang/Code/contest-361"

RETRY = [
    "JD027","JD047","JD053","JD065","JD104","JD116","JD118",
    "JD121","JD124","JD127","JD130",
    "JD134","JD135","JD137","JD139","JD140"
]

PROBLEM_IDS = {f"JD{i:03d}": pid for i, pid in enumerate(range(7292, 7432), 1)}

def get_csrf():
    try:
        with open(COOKIE_FILE) as f:
            for line in f:
                if 'csrftoken' in line and not line.startswith('#'):
                    return line.split('\t')[-1].strip()
    except: pass
    return ""

def curl_post(url, payload):
    csrf = get_csrf()
    cmd = ["curl", "-s", "-b", COOKIE_FILE, "-H", "Content-Type: application/json",
           "-H", f"X-CSRFToken: {csrf}", "-d", json.dumps(payload), url]
    r = subprocess.run(cmd, capture_output=True, text=True, timeout=30)
    try: return json.loads(r.stdout)
    except: return {"error": "parse_error"}

def submit(pid, code):
    return curl_post(f"{BASE_URL}/api/submission", {
        "problem_id": pid, "contest_id": CONTEST_ID, "language": "C++", "code": code
    })

def join_contest():
    csrf = get_csrf()
    r = subprocess.run(["curl", "-s", "-b", COOKIE_FILE, "-H", "Content-Type: application/json",
        "-H", f"X-CSRFToken: {csrf}", "-d", json.dumps({"contest_id": CONTEST_ID, "password": PASSWORD}),
        f"{BASE_URL}/api/contest/password"], capture_output=True, text=True, timeout=30)
    try:
        d = json.loads(r.stdout)
        return d.get("error") is None and d.get("data") == True
    except: return False

def get_result(sid):
    url = f"{BASE_URL}/api/submission?id={sid}"
    for _ in range(120):
        r = subprocess.run(["curl", "-s", "-b", COOKIE_FILE, url], capture_output=True, text=True, timeout=10)
        try:
            d = json.loads(r.stdout)
            if d.get("error") is None and d.get("data"):
                info = d["data"]
                if info.get("result") is not None:
                    return info
        except: pass
        time.sleep(0.5)
    return None

RESULT_NAMES = {0:"Accepted",-1:"Wrong Answer",-2:"TLE",-3:"MLE",-4:"RE",-5:"CE",-6:"PE"}

def main():
    if not os.path.exists(COOKIE_FILE):
        print("ERROR: Cookie not found"); sys.exit(1)
    print("Joining contest...", end=" ", flush=True)
    if not join_contest():
        print("FAILED!"); sys.exit(1)
    print("OK")

    results = {}
    for did in RETRY:
        pid = PROBLEM_IDS[did]
        cf = os.path.join(SOLUTION_DIR, f"{did}-problem", "main.cpp")
        if not os.path.exists(cf):
            print(f"{did}: FILE NOT FOUND")
            results[did] = ("NO_FILE",0)
            continue
        with open(cf) as f: code = f.read()

        while True:
            resp = submit(pid, code)
            if resp.get("error") is None and resp.get("data",{}).get("submission_id"):
                sid = resp["data"]["submission_id"]
                break
            err = str(resp.get("data",""))
            wait = int(re.search(r'(\d+)', err).group(1)) + 1 if re.search(r'(\d+)', err) else 15
            print(f"\r{did}: waiting {wait}s...", end="", flush=True)
            time.sleep(wait)

        print(f"\r{did}: judging...", end="", flush=True)
        result = get_result(sid)
        if result:
            code = result.get("result", -999)
            name = RESULT_NAMES.get(code, f"Unknown({code})")
            tc = result.get("info",{}).get("data",[])
            if tc:
                passed = sum(1 for t in tc if t.get("result")==0)
                score = sum(t.get("score",0) for t in tc)
                print(f"\r{did}: {name} ({passed}/{len(tc)}, score={score})" + " "*20)
            else:
                print(f"\r{did}: {name}" + " "*20)
            results[did] = (name, score if tc else 0)
        else:
            print(f"\r{did}: timeout" + " "*20)
            results[did] = ("TIMEOUT", 0)
        sys.stdout.flush()
        if did != RETRY[-1]:
            time.sleep(15)

    print(f"\n{'='*60}")
    ok = [(k,v) for k,v in results.items() if v[0] == "Accepted"]
    fail = [(k,v) for k,v in results.items() if v[0] != "Accepted"]
    print(f"Accepted: {len(ok)}/{len(results)}")
    if fail:
        print(f"Still failing ({len(fail)}):")
        for did, (name, score) in fail:
            print(f"  {did}: {name} ({score})")
    else:
        print("ALL ACCEPTED!")

if __name__ == "__main__":
    main()

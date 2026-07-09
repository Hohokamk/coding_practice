#!/usr/bin/env python3
"""Submit all solutions and check results, with rate-limit handling."""
import json
import subprocess
import sys
import time
import os

BASE_URL = "http://xmuoj.com"
CONTEST_ID = 361
PASSWORD = "ilovexmu"
COOKIE_FILE = "/tmp/xmuoj_cookies.txt"
SOLUTION_DIR = os.path.dirname(os.path.abspath(__file__))

PROBLEM_IDS = {
    "JD001": 7292, "JD002": 7293, "JD003": 7294, "JD004": 7295, "JD005": 7296,
    "JD006": 7297, "JD007": 7298, "JD008": 7299, "JD009": 7300, "JD010": 7301,
    "JD011": 7302, "JD012": 7303, "JD013": 7304, "JD014": 7305, "JD015": 7306,
    "JD016": 7307, "JD017": 7308, "JD018": 7309, "JD019": 7310, "JD020": 7311,
    "JD021": 7312, "JD022": 7313, "JD023": 7314, "JD024": 7315, "JD025": 7316,
    "JD026": 7317, "JD027": 7318, "JD028": 7319, "JD029": 7320, "JD030": 7321,
    "JD031": 7322, "JD032": 7323, "JD033": 7324, "JD034": 7325, "JD035": 7326,
    "JD036": 7327, "JD037": 7328, "JD038": 7329, "JD039": 7330, "JD040": 7331,
    "JD041": 7332, "JD042": 7333, "JD043": 7334, "JD044": 7335, "JD045": 7336,
    "JD046": 7337, "JD047": 7338, "JD048": 7339, "JD049": 7340, "JD050": 7341,
    "JD051": 7342, "JD052": 7343, "JD053": 7344, "JD054": 7345, "JD055": 7346,
    "JD056": 7347, "JD057": 7348, "JD058": 7349, "JD059": 7350, "JD060": 7351,
    "JD061": 7352, "JD062": 7353, "JD063": 7354, "JD064": 7355, "JD065": 7356,
    "JD066": 7357, "JD067": 7358, "JD068": 7359, "JD069": 7360, "JD070": 7361,
    "JD071": 7362, "JD072": 7363, "JD073": 7364, "JD074": 7365, "JD075": 7366,
    "JD076": 7367, "JD077": 7368, "JD078": 7369, "JD079": 7370, "JD080": 7371,
    "JD081": 7372, "JD082": 7373, "JD083": 7374, "JD084": 7375, "JD085": 7376,
    "JD086": 7377, "JD087": 7378, "JD088": 7379, "JD089": 7380, "JD090": 7381,
    "JD091": 7382, "JD092": 7383, "JD093": 7384, "JD094": 7385, "JD095": 7386,
    "JD096": 7387, "JD097": 7388, "JD098": 7389, "JD099": 7390, "JD100": 7391,
    "JD101": 7392, "JD102": 7393, "JD103": 7394, "JD104": 7395, "JD105": 7396,
    "JD106": 7397, "JD107": 7398, "JD108": 7399, "JD109": 7400, "JD110": 7401,
    "JD111": 7402, "JD112": 7403, "JD113": 7404, "JD114": 7405, "JD115": 7406,
    "JD116": 7407, "JD117": 7408, "JD118": 7409, "JD119": 7410, "JD120": 7411,
    "JD121": 7412, "JD122": 7413, "JD123": 7414, "JD124": 7415, "JD125": 7416,
    "JD126": 7417, "JD127": 7418, "JD128": 7419, "JD129": 7420, "JD130": 7421,
    "JD131": 7422, "JD132": 7423, "JD133": 7424, "JD134": 7425, "JD135": 7426,
    "JD136": 7427, "JD137": 7428, "JD138": 7429, "JD139": 7430, "JD140": 7431,
}

def get_csrf():
    try:
        with open(COOKIE_FILE) as f:
            for line in f:
                if 'csrftoken' in line and not line.startswith('#'):
                    return line.split('\t')[-1].strip()
    except:
        pass
    return ""

def join_contest():
    csrf = get_csrf()
    payload = json.dumps({"contest_id": CONTEST_ID, "password": PASSWORD})
    cmd = ["curl", "-s", "-b", COOKIE_FILE, "-H", "Content-Type: application/json",
           "-H", f"X-CSRFToken: {csrf}", "-d", payload, f"{BASE_URL}/api/contest/password"]
    result = subprocess.run(cmd, capture_output=True, text=True, timeout=30)
    try:
        data = json.loads(result.stdout)
        return data.get("error") is None and data.get("data") == True
    except:
        return False

def curl_post(url, payload):
    csrf = get_csrf()
    cmd = ["curl", "-s", "-b", COOKIE_FILE, "-H", "Content-Type: application/json",
           "-H", f"X-CSRFToken: {csrf}", "-d", json.dumps(payload), url]
    result = subprocess.run(cmd, capture_output=True, text=True, timeout=30)
    try:
        return json.loads(result.stdout)
    except:
        return {"error": "parse_error", "data": result.stdout[:200]}

def submit(problem_id, code):
    return curl_post(f"{BASE_URL}/api/submission", {
        "problem_id": problem_id,
        "contest_id": CONTEST_ID,
        "language": "C++",
        "code": code
    })

def get_submission_result(submission_id):
    url = f"{BASE_URL}/api/submission?id={submission_id}"
    for _ in range(120):
        result = subprocess.run(["curl", "-s", "-b", COOKIE_FILE, url],
                              capture_output=True, text=True, timeout=10)
        try:
            data = json.loads(result.stdout)
            if data.get("error") is None and data.get("data"):
                info = data["data"]
                result_code = info.get("result")
                if result_code is not None and result_code != -1:  # not pending
                    return info
        except:
            pass
        time.sleep(0.5)
    return None

def parse_wait_time(err_msg):
    """Parse 'Please wait X seconds' to get wait time."""
    import re
    match = re.search(r'(\d+)', str(err_msg))
    if match:
        return int(match.group(1))
    return 15

RESULT_NAMES = {
    0: "Accepted",
    -1: "Wrong Answer",
    -2: "Time Limit Exceeded",
    -3: "Memory Limit Exceeded",
    -4: "Runtime Error",
    -5: "Compile Error",
    -6: "Presentation Error",
}

def main():
    if not os.path.exists(COOKIE_FILE):
        print("ERROR: Cookie file not found.")
        sys.exit(1)

    print("Joining contest...", end=" ", flush=True)
    if not join_contest():
        print("FAILED!")
        sys.exit(1)
    print("OK")

    results = []

    # Submit in order
    for did in sorted(PROBLEM_IDS.keys()):
        pid = PROBLEM_IDS[did]
        code_file = os.path.join(SOLUTION_DIR, f"{did}-problem", "main.cpp")

        if not os.path.exists(code_file):
            print(f"{did}: FILE NOT FOUND")
            results.append((did, "FILE_NOT_FOUND"))
            continue

        with open(code_file) as f:
            code = f.read()

        # Submit with retry handling rate limits
        while True:
            resp = submit(pid, code)

            if resp.get("error") is None and resp.get("data"):
                sid = resp["data"].get("submission_id")
                if sid:
                    break  # Success

            err_msg = resp.get("data", "")
            if "wait" in str(err_msg).lower() or "second" in str(err_msg).lower():
                wait = parse_wait_time(err_msg) + 1
                print(f"\r{did}: rate limited, waiting {wait}s...", end="", flush=True)
                time.sleep(wait)
            else:
                print(f"\n{did}: SUBMIT ERROR: {err_msg}")
                results.append((did, f"SUBMIT_ERROR: {err_msg}"))
                break
        else:
            continue  # skip result checking if submit failed

        print(f"\r{did} (ID={pid}): submitted {sid[:16]}... judging...", end="", flush=True)

        # Wait for judgment
        result = get_submission_result(sid)
        if result:
            code = result.get("result", -999)
            name = RESULT_NAMES.get(code, f"Unknown({code})")
            # Get score if available
            info = result.get("info", {})
            test_data = info.get("data", [])
            if test_data:
                passed = sum(1 for t in test_data if t.get("result") == 0)
                total = len(test_data)
                score = sum(t.get("score", 0) for t in test_data)
                print(f"\r{did}: {name} ({passed}/{total} tests, score={score})" + " " * 20)
            else:
                print(f"\r{did}: {name}" + " " * 20)
            results.append((did, name))
        else:
            print(f"\r{did}: judgment timeout" + " " * 20)
            results.append((did, "JUDGMENT_TIMEOUT"))

        sys.stdout.flush()

        # Wait 15 seconds between submissions to avoid rate limits
        if did != "JD140":
            time.sleep(15)

    # Summary
    print(f"\n{'='*60}")
    accepted = [r for r in results if r[1] == "Accepted"]
    failed = [r for r in results if r[1] != "Accepted"]
    print(f"Accepted: {len(accepted)}/{len(results)}")
    if failed:
        print(f"Failed ({len(failed)}):")
        for did, reason in failed:
            print(f"  {did}: {reason}")
    else:
        print("All problems accepted! 🎉")

if __name__ == "__main__":
    main()

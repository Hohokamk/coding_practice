#!/usr/bin/env python3
"""
Batch submit all 140 solutions to XMUOJ Contest 361.
Usage: python3 submit_all.py

Before running, make sure you're logged in to XMUOJ:
  curl -c /tmp/xmuoj_cookies.txt "http://xmuoj.com/api/login" \
    -X POST -H "Content-Type: application/json" \
    -d '{"username":"YOUR_USERNAME","password":"YOUR_PASSWORD"}'
"""
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

# Problem ID mapping (from contest workspace data)
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

def join_contest():
    """Join password-protected contest before submitting"""
    csrf = get_csrf()
    payload = json.dumps({"contest_id": CONTEST_ID, "password": PASSWORD})
    cmd = [
        "curl", "-s", "-b", COOKIE_FILE,
        "-H", "Content-Type: application/json",
        "-H", f"X-CSRFToken: {csrf}",
        "-d", payload,
        f"{BASE_URL}/api/contest/password"
    ]
    result = subprocess.run(cmd, capture_output=True, text=True, timeout=30)
    try:
        data = json.loads(result.stdout)
        return data.get("error") is None and data.get("data") == True
    except:
        return False

def get_csrf():
    try:
        with open(COOKIE_FILE) as f:
            for line in f:
                if 'csrftoken' in line and not line.startswith('#'):
                    return line.split('\t')[-1].strip()
    except:
        pass
    return ""

def submit(problem_id, code):
    csrf = get_csrf()
    payload = json.dumps({
        "problem_id": problem_id,
        "contest_id": CONTEST_ID,
        "language": "C++",
        "code": code
    })

    cmd = [
        "curl", "-s", "-b", COOKIE_FILE,
        "-H", "Content-Type: application/json",
        "-H", f"X-CSRFToken: {csrf}",
        "-d", payload,
        f"{BASE_URL}/api/submission"
    ]

    result = subprocess.run(cmd, capture_output=True, text=True, timeout=30)
    try:
        return json.loads(result.stdout)
    except:
        return {"raw": result.stdout[:200]}

def get_submission_result(submission_id):
    url = f"{BASE_URL}/api/plugin/submission?submission_id={submission_id}"
    for _ in range(60):  # max 60 retries, ~30 seconds
        result = subprocess.run(
            ["curl", "-s", "-b", COOKIE_FILE, url],
            capture_output=True, text=True, timeout=10
        )
        try:
            data = json.loads(result.stdout)
            if data.get("data"):
                status = data["data"].get("result_label", "Pending")
                if status not in ("Pending", "Judging", "Waiting"):
                    return data["data"]
        except:
            pass
        time.sleep(0.5)
    return None

def main():
    if not os.path.exists(COOKIE_FILE):
        print("ERROR: Cookie file not found. Please login first.")
        sys.exit(1)

    # Join contest first
    print("Joining contest...", end=" ", flush=True)
    if not join_contest():
        print("FAILED! Check contest password.")
        sys.exit(1)
    print("OK")

    results = {"success": [], "failed": []}

    for did in sorted(PROBLEM_IDS.keys()):
        pid = PROBLEM_IDS[did]
        code_file = os.path.join(SOLUTION_DIR, f"{did}-problem", "main.cpp")

        if not os.path.exists(code_file):
            print(f"{did}: FILE NOT FOUND")
            results["failed"].append(did)
            continue

        with open(code_file) as f:
            code = f.read()

        print(f"Submitting {did} (ID={pid})...", end=" ", flush=True)
        resp = submit(pid, code)

        if resp.get("error") is None and resp.get("data"):
            sid = resp["data"].get("submission_id", "")
            if sid:
                print(f"OK (submission={sid})")
                results["success"].append(did)
            else:
                print(f"NO ID: {resp}")
                results["failed"].append(did)
        else:
            err = resp.get("data", resp.get("raw", "unknown"))
            print(f"FAILED: {err}")
            results["failed"].append(did)

        time.sleep(0.3)  # Rate limiting

    print(f"\n{'='*50}")
    print(f"Results: {len(results['success'])} success, {len(results['failed'])} failed")
    if results["failed"]:
        print(f"Failed: {', '.join(results['failed'])}")

if __name__ == "__main__":
    main()

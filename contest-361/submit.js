/**
 * Batch submit all solutions to XMUOJ Contest 361.
 * Uses same approach as the VS Code extension (Node.js + fetch).
 *
 * Usage: node submit.js [START_INDEX] [END_INDEX]
 *   node submit.js        # Submit ALL 140 problems
 *   node submit.js 1 10   # Submit JD001-JD010 only
 */

const fs = require('fs');
const path = require('path');

const BASE_URL = 'http://xmuoj.com';
const CONTEST_ID = 361;
const PASSWORD = 'ilovexmu';
const COOKIE_FILE = '/tmp/xmuoj_cookies.txt';
const SOLUTION_DIR = __dirname;

// Problem ID mapping
const PROBLEM_IDS = {
  JD001:7292,JD002:7293,JD003:7294,JD004:7295,JD005:7296,
  JD006:7297,JD007:7298,JD008:7299,JD009:7300,JD010:7301,
  JD011:7302,JD012:7303,JD013:7304,JD014:7305,JD015:7306,
  JD016:7307,JD017:7308,JD018:7309,JD019:7310,JD020:7311,
  JD021:7312,JD022:7313,JD023:7314,JD024:7315,JD025:7316,
  JD026:7317,JD027:7318,JD028:7319,JD029:7320,JD030:7321,
  JD031:7322,JD032:7323,JD033:7324,JD034:7325,JD035:7326,
  JD036:7327,JD037:7328,JD038:7329,JD039:7330,JD040:7331,
  JD041:7332,JD042:7333,JD043:7334,JD044:7335,JD045:7336,
  JD046:7337,JD047:7338,JD048:7339,JD049:7340,JD050:7341,
  JD051:7342,JD052:7343,JD053:7344,JD054:7345,JD055:7346,
  JD056:7347,JD057:7348,JD058:7349,JD059:7350,JD060:7351,
  JD061:7352,JD062:7353,JD063:7354,JD064:7355,JD065:7356,
  JD066:7357,JD067:7358,JD068:7359,JD069:7360,JD070:7361,
  JD071:7362,JD072:7363,JD073:7364,JD074:7365,JD075:7366,
  JD076:7367,JD077:7368,JD078:7369,JD079:7370,JD080:7371,
  JD081:7372,JD082:7373,JD083:7374,JD084:7375,JD085:7376,
  JD086:7377,JD087:7378,JD088:7379,JD089:7380,JD090:7381,
  JD091:7382,JD092:7383,JD093:7384,JD094:7385,JD095:7386,
  JD096:7387,JD097:7388,JD098:7389,JD099:7390,JD100:7391,
  JD101:7392,JD102:7393,JD103:7394,JD104:7395,JD105:7396,
  JD106:7397,JD107:7398,JD108:7399,JD109:7400,JD110:7401,
  JD111:7402,JD112:7403,JD113:7404,JD114:7405,JD115:7406,
  JD116:7407,JD117:7408,JD118:7409,JD119:7410,JD120:7411,
  JD121:7412,JD122:7413,JD123:7414,JD124:7415,JD125:7416,
  JD126:7417,JD127:7418,JD128:7419,JD129:7420,JD130:7421,
  JD131:7422,JD132:7423,JD133:7424,JD134:7425,JD135:7426,
  JD136:7427,JD137:7428,JD138:7429,JD139:7430,JD140:7431,
};

function parseCookies(content) {
  const jar = {};
  for (const line of content.split('\n')) {
    if (line.startsWith('#') || !line.trim()) continue;
    const parts = line.split('\t');
    if (parts.length >= 7) jar[parts[5]] = parts[6];
  }
  return jar;
}

function getCookieString(jar) {
  return Object.entries(jar).map(([k, v]) => `${k}=${v}`).join('; ');
}

async function submit(problemId, code, cookies) {
  const headers = {
    'Content-Type': 'application/json',
    'Cookie': getCookieString(cookies),
    'X-CSRFToken': cookies.csrftoken || '',
    'Connection': 'close',
    'User-Agent': 'Mozilla/5.0 (compatible; XMUOJ-VSCode-Plugin)',
  };

  const body = JSON.stringify({
    problem_id: problemId,
    contest_id: CONTEST_ID,
    contest_password: PASSWORD,
    language: 'C++',
    code: code,
  });

  const resp = await fetch(`${BASE_URL}/api/plugin/submission`, {
    method: 'POST',
    headers,
    body,
  });

  const text = await resp.text();
  try {
    return JSON.parse(text);
  } catch {
    return { raw: text, status: resp.status };
  }
}

async function submitAlt(problemId, code, cookies) {
  const headers = {
    'Content-Type': 'application/json',
    'Cookie': getCookieString(cookies),
    'X-CSRFToken': cookies.csrftoken || '',
    'Connection': 'close',
  };

  const body = JSON.stringify({
    problem_id: problemId,
    contest_id: CONTEST_ID,
    contest_password: PASSWORD,
    language: 'C++',
    code: code,
  });

  const resp = await fetch(`${BASE_URL}/api/submission`, {
    method: 'POST',
    headers,
    body,
  });

  const text = await resp.text();
  try {
    return JSON.parse(text);
  } catch {
    return { raw: text, status: resp.status };
  }
}

function sleep(ms) {
  return new Promise(resolve => setTimeout(resolve, ms));
}

async function main() {
  const args = process.argv.slice(2);
  const startIdx = parseInt(args[0]) || 1;
  const endIdx = parseInt(args[1]) || 140;

  // Read cookies
  let cookieContent;
  try {
    cookieContent = fs.readFileSync(COOKIE_FILE, 'utf8');
  } catch {
    console.error('ERROR: Cookie file not found. Please login first.');
    console.error('Run: curl -c /tmp/xmuoj_cookies.txt "http://xmuoj.com/api/login" -X POST -H "Content-Type: application/json" -d \'{"username":"YOUR_USERNAME","password":"YOUR_PASSWORD"}\'');
    process.exit(1);
  }
  const cookies = parseCookies(cookieContent);
  console.log(`Session: csrftoken=${(cookies.csrftoken || '').slice(0, 10)}...`);

  const allDids = Object.keys(PROBLEM_IDS).sort();
  const dids = allDids.filter(d => {
    const num = parseInt(d.replace('JD', ''));
    return num >= startIdx && num <= endIdx;
  });

  console.log(`Submitting ${dids.length} solutions (JD${String(startIdx).padStart(3,'0')} to JD${String(endIdx).padStart(3,'0')})...\n`);

  let success = 0, failed = 0;
  const failures = [];

  for (const did of dids) {
    const pid = PROBLEM_IDS[did];
    const codeFile = path.join(SOLUTION_DIR, `${did}-problem`, 'main.cpp');

    if (!fs.existsSync(codeFile)) {
      console.log(`${did}: FILE NOT FOUND`);
      failures.push(did);
      failed++;
      continue;
    }

    const code = fs.readFileSync(codeFile, 'utf8');
    process.stdout.write(`${did} (ID=${pid})... `);

    try {
      let result = await submit(pid, code, cookies);

      // If plugin API fails, try alternative
      if (result.status === 404 || result.raw) {
        result = await submitAlt(pid, code, cookies);
      }

      if (result.error === null && result.data?.submission_id) {
        console.log(`OK (submission_id=${result.data.submission_id})`);
        success++;
      } else if (result.data === 'Succeeded' || result.data?.result_label) {
        console.log(`OK (${result.data.result_label || result.data})`);
        success++;
      } else {
        const err = result.data || result.error || JSON.stringify(result).slice(0, 80);
        console.log(`FAIL: ${err}`);
        failures.push(did);
        failed++;
      }
    } catch (e) {
      console.log(`ERROR: ${e.message}`);
      failures.push(did);
      failed++;
    }

    // Rate limiting
    await sleep(500);
  }

  console.log(`\n${'='.repeat(50)}`);
  console.log(`Results: ${success} success, ${failed} failed`);
  if (failures.length > 0) {
    console.log(`Failed: ${failures.join(', ')}`);
  }
}

main().catch(console.error);

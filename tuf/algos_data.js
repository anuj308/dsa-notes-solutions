// algos_data.js — reference cheat sheet (NOT user's code; AI-written templates)
'use strict';

const L = a => a.map(x => ({ name: x[0], url: x[1], diff: x[2] }));

const algorithms = [
/* ============ ARRAYS & HASHING ============ */
{
  topic: 'Arrays & Hashing', name: 'Frequency Map / Counting', what: 'Track how often each value appears using a hash map (or a fixed-size array when the value range is small).', when: 'Duplicated values, anagrams, "count pairs/subarrays with property", highest/lowest frequency, first unique element.', tc: 'O(n)', sc: 'O(n) (or O(range) with array hashing)',
  template: {
    cpp: `// Frequency counting — array hash (values 0..k) and map hash
int freq[100001] = {0};                 // array hash: fastest when range is small
for (int x : arr) freq[x]++;

unordered_map<int,int> cnt;             // map hash: any value range
for (int x : arr) cnt[x]++;
int mx = 0, mn = INT_MAX, mxVal, mnVal;
for (auto &p : cnt) {
    if (p.second > mx) { mx = p.second; mxVal = p.first; }
    if (p.second < mn) { mn = p.second; mnVal = p.first; }
}`,
    python: `from collections import Counter
cnt = Counter(arr)              # frequency of every element
mx_val = max(cnt, key=cnt.get)  # element with highest frequency
mn_val = min(cnt, key=cnt.get)  # element with lowest frequency

# array hash when values are 0..k
freq = [0] * (k + 1)
for x in arr:
    freq[x] += 1`,
    java: `Map<Integer, Integer> cnt = new HashMap<>();
for (int x : arr) cnt.merge(x, 1, Integer::sum);

int mxVal = 0, mnVal = 0, mx = Integer.MIN_VALUE, mn = Integer.MAX_VALUE;
for (var e : cnt.entrySet()) {
    if (e.getValue() > mx) { mx = e.getValue(); mxVal = e.getKey(); }
    if (e.getValue() < mn) { mn = e.getValue(); mnVal = e.getKey(); }
}`
  },
  problems: L([
    ['Two Sum','https://leetcode.com/problems/two-sum/','Easy'],
    ['Contains Duplicate','https://leetcode.com/problems/contains-duplicate/','Easy'],
    ['Group Anagrams','https://leetcode.com/problems/group-anagrams/','Medium'],
    ['Top K Frequent Elements','https://leetcode.com/problems/top-k-frequent-elements/','Medium'],
    ['Longest Consecutive Sequence','https://leetcode.com/problems/longest-consecutive-sequence/','Medium']
  ]),
  pitfalls: ['Array hashing needs non-negative / bounded values — check the constraint first.', 'unordered_map worst case O(n) per op (adversarial input); map guarantees O(log n).', 'For anagrams: count 26 letters, don\'t sort every string (O(n·k) beats O(n·k log k)).']
},
{
  topic: 'Arrays & Hashing', name: 'Bucket Sort on Frequency', what: 'Bucket indices = frequency, so you can get "top K frequent" without a heap or full sort.', when: '"Top K frequent …", "sort by frequency", when you want O(n) instead of O(n log n).', tc: 'O(n)', sc: 'O(n)',
  template: {
    cpp: `vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int,int> cnt;
    for (int x : nums) cnt[x]++;
    int n = nums.size();
    vector<vector<int>> buckets(n + 1);         // buckets[f] = values with frequency f
    for (auto &p : cnt) buckets[p.second].push_back(p.first);
    vector<int> ans;
    for (int f = n; f >= 0 && (int)ans.size() < k; f--)
        for (int v : buckets[f]) { ans.push_back(v); if ((int)ans.size() == k) break; }
    return ans;
}`,
    python: `def top_k_frequent(nums, k):
    cnt = collections.Counter(nums)
    buckets = [[] for _ in range(len(nums) + 1)]
    for v, f in cnt.items():
        buckets[f].append(v)
    ans = []
    for f in range(len(buckets) - 1, 0, -1):
        for v in buckets[f]:
            ans.append(v)
            if len(ans) == k:
                return ans
    return ans`,
    java: `public int[] topKFrequent(int[] nums, int k) {
    Map<Integer, Integer> cnt = new HashMap<>();
    for (int x : nums) cnt.merge(x, 1, Integer::sum);
    List<List<Integer>> buckets = new ArrayList<>(nums.length + 1);
    for (int i = 0; i <= nums.length; i++) buckets.add(new ArrayList<>());
    for (var e : cnt.entrySet()) buckets.get(e.getValue()).add(e.getKey());
    int[] ans = new int[k]; int idx = 0;
    for (int f = buckets.size() - 1; f >= 0 && idx < k; f--)
        for (int v : buckets.get(f)) { ans[idx++] = v; if (idx == k) break; }
    return ans;
}`
  },
  problems: L([
    ['Top K Frequent Elements','https://leetcode.com/problems/top-k-frequent-elements/','Medium'],
    ['Top K Frequent Words','https://leetcode.com/problems/top-k-frequent-words/','Medium'],
    ['Sort Characters By Frequency','https://leetcode.com/problems/sort-characters-by-frequency/','Medium']
  ]),
  pitfalls: ['Frequency can be at most n, so buckets array size is n+1.', 'Multiple values may share a frequency — the problem usually allows any order (check).']
},

/* ============ TWO POINTERS ============ */
{
  topic: 'Two Pointers', name: 'Opposite-Ends (Converging) Two Pointers', what: 'Start pointers at both ends of a sorted range and move them toward each other based on a comparison.', when: 'Sorted array pair-sum (Two Sum II), palindrome check, container/trapping water, 3Sum inner loop, reversing in place.', tc: 'O(n)', sc: 'O(1)',
  template: {
    cpp: `// Two Sum II on sorted array
int l = 0, r = n - 1;
while (l < r) {
    int sum = a[l] + a[r];
    if (sum == target) return {l, r};
    else if (sum < target) l++;   // need bigger sum
    else r--;                     // need smaller sum
}
return {};`,
    python: `l, r = 0, len(a) - 1
while l < r:
    s = a[l] + a[r]
    if s == target:
        return [l, r]
    if s < target:
        l += 1      # need bigger sum
    else:
        r -= 1      # need smaller sum
return []`,
    java: `int l = 0, r = a.length - 1;
while (l < r) {
    int sum = a[l] + a[r];
    if (sum == target) return new int[]{l, r};
    else if (sum < target) l++;
    else r--;
}
return new int[]{};`
  },
  problems: L([
    ['Two Sum II - Input Array Is Sorted','https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/','Medium'],
    ['Valid Palindrome','https://leetcode.com/problems/valid-palindrome/','Easy'],
    ['3Sum','https://leetcode.com/problems/3sum/','Medium'],
    ['Container With Most Water','https://leetcode.com/problems/container-with-most-water/','Medium'],
    ['Trapping Rain Water','https://leetcode.com/problems/trapping-rain-water/','Hard']
  ]),
  pitfalls: ['The array must be sorted for the decision logic to be valid (or the problem must be positional, like water).', 'Skip duplicates carefully in 3Sum (l++/r-- past equal values) to avoid duplicate triplets.', 'while (l < r) vs while (l <= r) — pick by whether l==r is a valid pair.']
},
{
  topic: 'Two Pointers', name: 'Same-Direction (Read/Write) Two Pointers', what: 'One pointer reads elements, another writes the answer position — removes duplicates / moves zeroes in place.', when: '"Remove duplicates", "move zeroes", "merge two sorted arrays in place", partitioning.', tc: 'O(n)', sc: 'O(1)',
  template: {
    cpp: `// Remove duplicates from sorted array in place
int write = 1;
for (int read = 1; read < n; read++) {
    if (a[read] != a[write - 1]) a[write++] = a[read];
}
// write = new length`,
    python: `write = 1
for read in range(1, len(a)):
    if a[read] != a[write - 1]:
        a[write] = a[read]
        write += 1
# a[:write] is the deduplicated part`,
    java: `int write = 1;
for (int read = 1; read < a.length; read++) {
    if (a[read] != a[write - 1]) a[write++] = a[read];
}
// write = new length`
  },
  problems: L([
    ['Remove Duplicates from Sorted Array','https://leetcode.com/problems/remove-duplicates-from-sorted-array/','Easy'],
    ['Move Zeroes','https://leetcode.com/problems/move-zeroes/','Easy'],
    ['Merge Sorted Array','https://leetcode.com/problems/merge-sorted-array/','Easy'],
    ['Remove Element','https://leetcode.com/problems/remove-element/','Easy']
  ]),
  pitfalls: ['Compare a[read] against a[write-1], not a[read-1] (the written region is the truth).', 'For Merge Sorted Array, fill from the back so you don\'t overwrite nums1\'s data.']
},

/* ============ SLIDING WINDOW ============ */
{
  topic: 'Sliding Window', name: 'Fixed-Size Window', what: 'Slide a window of constant size k, adding the entering element and removing the leaving one each step.', when: '"Max/avg/min of every subarray of size k", first negative in window, any constant-window aggregate.', tc: 'O(n)', sc: 'O(1) or O(k)',
  template: {
    cpp: `long long sum = 0;
for (int i = 0; i < n; i++) {
    sum += a[i];                  // element enters the window
    if (i >= k) sum -= a[i - k];  // element (i-k) leaves
    if (i >= k - 1) {             // window [i-k+1 .. i] is complete
        // use sum here
    }
}`,
    python: `s = 0
for i in range(len(a)):
    s += a[i]
    if i >= k:
        s -= a[i - k]
    if i >= k - 1:
        pass  # window [i-k+1 .. i] is complete — use s`,
    java: `long sum = 0;
for (int i = 0; i < a.length; i++) {
    sum += a[i];
    if (i >= k) sum -= a[i - k];
    if (i >= k - 1) { /* window complete */ }
}`
  },
  problems: L([
    ['Maximum Average Subarray I','https://leetcode.com/problems/maximum-average-subarray-i/','Easy'],
    ['Sliding Window Maximum','https://leetcode.com/problems/sliding-window-maximum/','Hard'],
    ['First Negative In Every Window (GFG)','https://www.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1','Medium']
  ]),
  pitfalls: ['Start using results only after the first full window (i >= k-1).', 'For window maximum use a monotonic deque — a plain max() inside the loop is O(nk).']
},
{
  topic: 'Sliding Window', name: 'Variable-Size Window (Shrink While Invalid)', what: 'Expand right every step; when the window becomes invalid, shrink from the left until valid again.', when: '"Longest substring with …", "at most K distinct/zeroes", "smallest window containing …", subarray sum for non-negative arrays.', tc: 'O(n) — each index enters and leaves the window at most once', sc: 'O(k) or O(alphabet)',
  template: {
    cpp: `int left = 0, best = 0;
for (int right = 0; right < n; right++) {
    // 1. add a[right] to window state
    while (/* window invalid */) {          // 2. shrink while invalid
        // remove a[left] from window state
        left++;
    }
    best = max(best, right - left + 1);     // 3. window [left..right] is valid
}
return best;`,
    python: `left = 0
best = 0
for right in range(len(a)):
    # add a[right] to window state
    while invalid():           # shrink while window is invalid
        # remove a[left] from state
        left += 1
    best = max(best, right - left + 1)
return best`,
    java: `int left = 0, best = 0;
for (int right = 0; right < a.length; right++) {
    // add a[right] to window state
    while (/* window invalid */) {
        // remove a[left] from state
        left++;
    }
    best = Math.max(best, right - left + 1);
}
return best;`
  },
  problems: L([
    ['Longest Substring Without Repeating Characters','https://leetcode.com/problems/longest-substring-without-repeating-characters/','Medium'],
    ['Max Consecutive Ones III','https://leetcode.com/problems/max-consecutive-ones-iii/','Medium'],
    ['Longest Repeating Character Replacement','https://leetcode.com/problems/longest-repeating-character-replacement/','Medium'],
    ['Minimum Window Substring','https://leetcode.com/problems/minimum-window-substring/','Hard'],
    ['Count Substrings / Binary Subarrays With Sum','https://leetcode.com/problems/binary-subarrays-with-sum/','Medium']
  ]),
  pitfalls: ['"Exactly K" = atMost(K) − atMost(K−1) for counting variants.', 'Negative numbers break plain sliding windows for sums — use prefix-sum hashmap instead.', 'Two-pointer complexity argument only holds because left never moves backwards.']
},

/* ============ PREFIX SUM ============ */
{
  topic: 'Prefix Sum', name: 'Prefix Sum + Hash Map', what: 'pre[i] = sum of first i elements; a subarray (l..r] sums to k iff pre[r] − pre[l] = k — count/store prefix values in a map.', when: '"Subarray sum equals K", "count subarrays with property", range-sum queries, dividing arrays into equal-sum parts.', tc: 'O(n)', sc: 'O(n)',
  template: {
    cpp: `long long pre = 0, count = 0;
unordered_map<long long,int> seen;   // prefix value -> how many times seen
seen[0] = 1;                         // empty prefix
for (int i = 0; i < n; i++) {
    pre += a[i];
    count += seen[pre - k];          // earlier prefix with value pre-k
    seen[pre]++;
}
return count;`,
    python: `pre = 0
count = 0
seen = {0: 1}            # prefix value -> count of occurrences
for x in a:
    pre += x
    count += seen.get(pre - k, 0)
    seen[pre] = seen.get(pre, 0) + 1
return count`,
    java: `long pre = 0; long count = 0;
Map<Long, Integer> seen = new HashMap<>();
seen.put(0L, 1);
for (int x : a) {
    pre += x;
    count += seen.getOrDefault(pre - k, 0);
    seen.merge(pre, 1, Integer::sum);
}
return (int) count;`
  },
  problems: L([
    ['Subarray Sum Equals K','https://leetcode.com/problems/subarray-sum-equals-k/','Medium'],
    ['Find Pivot Index','https://leetcode.com/problems/find-pivot-index/','Easy'],
    ['Product of Array Except Self','https://leetcode.com/problems/product-of-array-except-self/','Medium'],
    ['Continuous Subarray Sum','https://leetcode.com/problems/continuous-subarray-sum/','Medium']
  ]),
  pitfalls: ['Initialize seen[0] = 1 or you miss subarrays starting at index 0.', 'Use 64-bit sums to avoid overflow.', 'For "subarray sum divisible by k" store pre mod k (fix negatives with ((x % k) + k) % k).']
},

/* ============ BINARY SEARCH ============ */
{
  topic: 'Binary Search', name: 'Classic Binary Search + Lower/Upper Bound', what: 'Halve the search space each step. Lower bound = first index with a[i] >= x; upper bound = first index with a[i] > x.', when: 'Sorted search, "first/last position", "insert position", "floor/ceil", "peak element" (any monotonic predicate).', tc: 'O(log n)', sc: 'O(1)',
  template: {
    cpp: `int lo = 0, hi = n - 1;      // search in [lo, hi]
while (lo <= hi) {
    int mid = lo + (hi - lo) / 2;
    if (a[mid] == target) return mid;
    else if (a[mid] < target) lo = mid + 1;
    else hi = mid - 1;
}
return -1;

// lower bound (first index with a[i] >= x) — answer form
int lo = 0, hi = n, ans = n;  // half-open [lo, hi)
while (lo < hi) {
    int mid = lo + (hi - lo) / 2;
    if (a[mid] >= x) hi = mid;
    else lo = mid + 1;
}
return lo;  // == upper bound if predicate is a[mid] > x`,
    python: `lo, hi = 0, len(a) - 1
while lo <= hi:
    mid = lo + (hi - lo) // 2
    if a[mid] == target: return mid
    elif a[mid] < target: lo = mid + 1
    else: hi = mid - 1
return -1

# lower bound — answer form
lo, hi = 0, len(a)      # half-open [lo, hi)
while lo < hi:
    mid = lo + (hi - lo) // 2
    if a[mid] >= x: hi = mid
    else: lo = mid + 1
return lo               # == bisect.bisect_left(a, x)`,
    java: `int lo = 0, hi = n - 1;
while (lo <= hi) {
    int mid = lo + (hi - lo) / 2;
    if (a[mid] == target) return mid;
    else if (a[mid] < target) lo = mid + 1;
    else hi = mid - 1;
}
return -1;

// lower bound — answer form
int lo = 0, hi = n;
while (lo < hi) {
    int mid = lo + (hi - lo) / 2;
    if (a[mid] >= x) hi = mid;
    else lo = mid + 1;
}
return lo;`
  },
  problems: L([
    ['Binary Search','https://leetcode.com/problems/binary-search/','Easy'],
    ['Find First and Last Position of Element in Sorted Array','https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/','Medium'],
    ['Search Insert Position','https://leetcode.com/problems/search-insert-position/','Easy'],
    ['Floor/Ceil in Sorted Array (GFG)','https://www.geeksforgeeks.org/problems/floor-in-a-sorted-array-1587115620/1','Easy']
  ]),
  pitfalls: ['mid = lo + (hi-lo)/2 avoids integer overflow (vs (lo+hi)/2).', 'lo <= hi with hi = mid-1 (inclusive form) vs lo < hi with hi = mid (half-open) — don\'t mix the two styles.', 'On the answer form, return lo and make sure the invariant "everything left of lo fails, everything right passes" holds.']
},
{
  topic: 'Binary Search', name: 'Binary Search on Answer', what: 'Search the answer space [min, max] directly when a monotonic predicate canCheck(x) exists.', when: '"Minimize the maximum" / "maximize the minimum": Koko bananas, ship packages in D days, allocate books, split array largest sum, aggressive cows.', tc: 'O(n log(range))', sc: 'O(1)',
  template: {
    cpp: `bool can(long long x) {          // monotonic predicate
    long long need = 0;
    for (int i = 0; i < n; i++) need += (a[i] + x - 1) / x;  // e.g. hours needed
    return need <= limit;
}
long long lo = 1, hi = 1e18, ans = -1;      // [lo, hi] search space of the answer
while (lo <= hi) {
    long long mid = lo + (hi - lo) / 2;
    if (can(mid)) { ans = mid; hi = mid - 1; }  // valid → try smaller
    else lo = mid + 1;                          // invalid → go bigger
}
return ans;`,
    python: `def can(x):
    need = 0
    for v in a:
        need += (v + x - 1) // x
    return need <= limit

lo, hi, ans = 1, 10**18, -1
while lo <= hi:
    mid = lo + (hi - lo) // 2
    if can(mid):
        ans = mid; hi = mid - 1   # valid → try smaller
    else:
        lo = mid + 1              # invalid → go bigger
return ans`,
    java: `boolean can(long x) {
    long need = 0;
    for (int v : a) need += (v + x - 1) / x;
    return need <= limit;
}
long lo = 1, hi = Long.MAX_VALUE, ans = -1;
while (lo <= hi) {
    long mid = lo + (hi - lo) / 2;
    if (can(mid)) { ans = mid; hi = mid - 1; }
    else lo = mid + 1;
}
return ans;`
  },
  problems: L([
    ['Koko Eating Bananas','https://leetcode.com/problems/koko-eating-bananas/','Medium'],
    ['Capacity To Ship Packages Within D Days','https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/','Medium'],
    ['Split Array Largest Sum','https://leetcode.com/problems/split-array-largest-sum/','Hard'],
    ['Aggressive Cows (GFG)','https://www.geeksforgeeks.org/problems/aggressive-cows/1','Hard'],
    ['Median of Two Sorted Arrays','https://leetcode.com/problems/median-of-two-sorted-arrays/','Hard']
  ]),
  pitfalls: ['The predicate must be monotonic: false…false true…true (or the reverse). Prove it before coding.', 'Careful with the answer bounds — include impossible corner cases (e.g. mid can be 0 → division by zero).', 'For "minimize max", record ans when valid and move hi = mid-1; for "maximize min", swap the sides.']
},
{
  topic: 'Binary Search', name: 'Rotated / Modified Binary Search', what: 'In a rotated sorted array, at least one half of [lo..mid] or [mid..hi] is still sorted — decide which half is sorted and recurse there.', when: 'Search in rotated sorted array, find minimum in rotated array, 2D matrix as 1D (LC 74), single element in sorted pairs (LC 540).', tc: 'O(log n)', sc: 'O(1)',
  template: {
    cpp: `int lo = 0, hi = n - 1;
while (lo < hi) {
    int mid = lo + (hi - lo) / 2;
    if (a[mid] > a[hi]) lo = mid + 1;   // min is strictly right of mid
    else hi = mid;                      // min is at mid or left
}
// a[lo] is the minimum; then do a normal search in the correct sorted half`,
    python: `lo, hi = 0, len(a) - 1
while lo < hi:
    mid = lo + (hi - lo) // 2
    if a[mid] > a[hi]:
        lo = mid + 1   # min is strictly right of mid
    else:
        hi = mid       # min is at mid or left
# a[lo] is the minimum`,
    java: `int lo = 0, hi = a.length - 1;
while (lo < hi) {
    int mid = lo + (hi - lo) / 2;
    if (a[mid] > a[hi]) lo = mid + 1;
    else hi = mid;
}
// a[lo] is the minimum`
  },
  problems: L([
    ['Search in Rotated Sorted Array','https://leetcode.com/problems/search-in-rotated-sorted-array/','Medium'],
    ['Find Minimum in Rotated Sorted Array','https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/','Medium'],
    ['Search a 2D Matrix','https://leetcode.com/problems/search-a-2d-matrix/','Medium'],
    ['Single Element in a Sorted Array','https://leetcode.com/problems/single-element-in-a-sorted-array/','Medium']
  ]),
  pitfalls: ['Compare against a[hi] (not a[lo]) to find the minimum — rotation point logic.', 'Duplicate pivots (LC 81) break the strict comparison; when a[mid]==a[hi], do hi-- (O(n) worst case).', 'In 2D search, treat r*m + c as the flattened index.']
},

/* ============ SORTING ============ */
{
  topic: 'Sorting', name: 'Merge Sort (Divide & Conquer)', what: 'Split in half, sort recursively, merge two sorted halves. Stable, predictable O(n log n).', when: 'Sorting with guaranteed O(n log n), counting inversions / reverse pairs, linked-list sorting, external sort.', tc: 'O(n log n)', sc: 'O(n)',
  template: {
    cpp: `void merge(vector<int>& a, int l, int m, int r) {
    vector<int> tmp;
    int i = l, j = m + 1;
    while (i <= m && j <= r) {
        if (a[i] <= a[j]) tmp.push_back(a[i++]);   // <= keeps it stable
        else tmp.push_back(a[j++]);
    }
    while (i <= m) tmp.push_back(a[i++]);
    while (j <= r) tmp.push_back(a[j++]);
    for (int k = 0; k < (int)tmp.size(); k++) a[l + k] = tmp[k];
}
void mergeSort(vector<int>& a, int l, int r) {
    if (l >= r) return;
    int m = l + (r - l) / 2;
    mergeSort(a, l, m);
    mergeSort(a, m + 1, r);
    merge(a, l, m, r);
}`,
    python: `def merge_sort(a):
    if len(a) <= 1:
        return a
    m = len(a) // 2
    left, right = merge_sort(a[:m]), merge_sort(a[m:])
    out, i, j = [], 0, 0
    while i < len(left) and j < len(right):
        if left[i] <= right[j]:        # <= keeps it stable
            out.append(left[i]); i += 1
        else:
            out.append(right[j]); j += 1
    return out + left[i:] + right[j:]`,
    java: `void mergeSort(int[] a, int l, int r) {
    if (l >= r) return;
    int m = l + (r - l) / 2;
    mergeSort(a, l, m);
    mergeSort(a, m + 1, r);
    int[] tmp = new int[r - l + 1];
    int i = l, j = m + 1, k = 0;
    while (i <= m && j <= r) tmp[k++] = (a[i] <= a[j]) ? a[i++] : a[j++];
    while (i <= m) tmp[k++] = a[i++];
    while (j <= r) tmp[k++] = a[j++];
    System.arraycopy(tmp, 0, a, l, tmp.length);
}`
  },
  problems: L([
    ['Sort an Array','https://leetcode.com/problems/sort-an-array/','Medium'],
    ['Merge Intervals','https://leetcode.com/problems/merge-intervals/','Medium'],
    ['Count Inversions (GFG)','https://www.geeksforgeeks.org/problems/inversion-of-array-1587115620/1','Hard'],
    ['Reverse Pairs','https://leetcode.com/problems/reverse-pairs/','Hard']
  ]),
  pitfalls: ['Use <= in merge for stability.', 'Counting inversions: when a[i] > a[j], all remaining left elements also invert — add (m - i + 1) at once.', 'Quick sort is in-place O(1) extra but O(n²) worst case; merge sort trades memory for guarantees.']
},
{
  topic: 'Sorting', name: 'Counting Sort / Bucket & Radix', what: 'Sort without comparisons by counting occurrences (small integer range) or digit-by-digit (radix).', when: 'Values in a small known range (0..k), ages/heights, "largest number", linear-time sorting requirements.', tc: 'O(n + k) counting; O(d·(n+b)) radix', sc: 'O(k) / O(n + b)',
  template: {
    cpp: `// counting sort for values 0..k (k small)
vector<int> cnt(k + 1, 0);
for (int x : a) cnt[x]++;
int idx = 0;
for (int v = 0; v <= k; v++)
    for (int c = 0; c < cnt[v]; c++)
        a[idx++] = v;`,
    python: `cnt = [0] * (k + 1)
for x in a:
    cnt[x] += 1
idx = 0
for v in range(k + 1):
    for _ in range(cnt[v]):
        a[idx] = v
        idx += 1`,
    java: `int[] cnt = new int[k + 1];
for (int x : a) cnt[x]++;
int idx = 0;
for (int v = 0; v <= k; v++)
    for (int c = 0; c < cnt[v]; c++) a[idx++] = v;`
  },
  problems: L([
    ['Sort Colors','https://leetcode.com/problems/sort-colors/','Medium'],
    ['Height Checker','https://leetcode.com/problems/height-checker/','Easy'],
    ['Largest Number','https://leetcode.com/problems/largest-number/','Medium']
  ]),
  pitfalls: ['Only works for a bounded value range — huge or negative ranges waste memory (shift negatives or use comparisons).', 'Counting sort is stable only in the prefix-sum variant.']
},
{
  topic: 'Sorting', name: 'Custom Comparator Patterns', what: 'sort() with a comparator: order by key, multiple keys, or an "unusual" ordering (e.g. a+b > b+a).', when: '"Largest number", sort by frequency then value, intervals by start/end, k-closest points.', tc: 'O(n log n)', sc: 'O(1)',
  template: {
    cpp: `// sort by x, tie-break by y descending
sort(v.begin(), v.end(), [](const auto& p, const auto& q) {
    if (p.first != q.first) return p.first < q.first;
    return p.second > q.second;
});
// largest number: order strings so that a+b > b+a
sort(strs.begin(), strs.end(), [](const string& a, const string& b) {
    return a + b > b + a;
});`,
    python: `v.sort(key=lambda p: (p[0], -p[1]))      # by x, tie y desc
strs.sort(key=functools.cmp_to_key(lambda a, b: -1 if a + b > b + a else 1))`,
    java: `v.sort((p, q) -> p[0] != q[0] ? Integer.compare(p[0], q[0]) : Integer.compare(q[1], p[1]));
Arrays.sort(strs, (a, b) -> (b + a).compareTo(a + b));`
  },
  problems: L([
    ['Largest Number','https://leetcode.com/problems/largest-number/','Medium'],
    ['K Closest Points to Origin','https://leetcode.com/problems/k-closest-points-to-origin/','Medium'],
    ['Sort Integers by The Number of 1 Bits','https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/','Easy']
  ]),
  pitfalls: ['Comparator must be a strict weak ordering — return false on equal keys, never a[i] <= a[j].', 'Comparing concatenated strings requires string comparison, not numeric (overflow/length issues).']
},

/* ============ RECURSION & BACKTRACKING ============ */
{
  topic: 'Recursion & Backtracking', name: 'Subsets / Power Set', what: 'At each element: pick it or skip it — a binary recursion tree of 2^n leaves.', when: '"All subsets", "combinations", "generate all …" with distinct elements; also bitmask enumeration.', tc: 'O(n · 2^n)', sc: 'O(n) recursion depth',
  template: {
    cpp: `vector<vector<int>> ans;
void gen(int i, vector<int>& a, vector<int>& cur) {
    if (i == (int)a.size()) { ans.push_back(cur); return; }
    cur.push_back(a[i]);      // pick a[i]
    gen(i + 1, a, cur);
    cur.pop_back();           // skip a[i]
    gen(i + 1, a, cur);
}
// handle duplicates: sort first; then
// if (i > start && a[i] == a[i-1]) continue;  (loop-style version)`,
    python: `ans = []
def gen(i, cur):
    if i == len(a):
        ans.append(cur[:])
        return
    cur.append(a[i])      # pick
    gen(i + 1, cur)
    cur.pop()             # skip
    gen(i + 1, cur)
gen(0, [])`,
    java: `List<List<Integer>> ans = new ArrayList<>();
void gen(int i, int[] a, List<Integer> cur) {
    if (i == a.length) { ans.add(new ArrayList<>(cur)); return; }
    cur.add(a[i]);        // pick
    gen(i + 1, a, cur);
    cur.remove(cur.size() - 1);  // skip
    gen(i + 1, a, cur);
}`
  },
  problems: L([
    ['Subsets','https://leetcode.com/problems/subsets/','Medium'],
    ['Subsets II (duplicates)','https://leetcode.com/problems/subsets-ii/','Medium'],
    ['Power Set (GFG)','https://www.geeksforgeeks.org/problems/power-set4302/1','Medium']
  ]),
  pitfalls: ['Copy cur into the answer (cur[:] / new ArrayList) — you always backtrack.', 'For duplicates: sort + skip equal siblings, otherwise you get repeated subsets.']
},
{
  topic: 'Recursion & Backtracking', name: 'Permutations', what: 'Fix each position by trying every unused element (swap in place or used[] mask).', when: '"All permutations", next permutation, distinct permutations with duplicates, string arrangements.', tc: 'O(n · n!)', sc: 'O(n)',
  template: {
    cpp: `vector<vector<int>> ans;
void gen(vector<int>& a, int idx) {
    if (idx == (int)a.size()) { ans.push_back(a); return; }
    for (int i = idx; i < (int)a.size(); i++) {
        swap(a[idx], a[i]);   // choose a[i] as the element at 'idx'
        gen(a, idx + 1);
        swap(a[idx], a[i]);   // backtrack
    }
}`,
    python: `ans = []
def gen(idx):
    if idx == len(a):
        ans.append(a[:])
        return
    for i in range(idx, len(a)):
        a[idx], a[i] = a[i], a[idx]
        gen(idx + 1)
        a[idx], a[i] = a[i], a[idx]
gen(0)`,
    java: `List<List<Integer>> ans = new ArrayList<>();
void gen(int[] a, int idx) {
    if (idx == a.length) { ans.add(toList(a)); return; }
    for (int i = idx; i < a.length; i++) {
        swap(a, idx, i);
        gen(a, idx + 1);
        swap(a, idx, i);
    }
}`
  },
  problems: L([
    ['Permutations','https://leetcode.com/problems/permutations/','Medium'],
    ['Permutations II','https://leetcode.com/problems/permutations-ii/','Medium'],
    ['Next Permutation','https://leetcode.com/problems/next-permutation/','Medium']
  ]),
  pitfalls: ['With duplicates, swap-in-place breaks order — prefer the used[] + sorted-skip pattern.', 'Next permutation: find longest non-increasing suffix, swap pivot with smallest larger element from the suffix, then reverse the suffix.']
},
{
  topic: 'Recursion & Backtracking', name: 'Combination Sum (Pick / Not-Pick with Reuse)', what: 'DFS with a start index; when elements may repeat, recurse with the same index (stay), else move to idx+1.', when: '"Combination sum I/II/III", coin change ways, subsets with target sum.', tc: 'O(2^t) where t = target (worst)', sc: 'O(t) recursion depth',
  template: {
    cpp: `void dfs(int idx, int remaining, vector<int>& a, vector<int>& cur, vector<vector<int>>& ans) {
    if (idx == (int)a.size() || remaining < 0) return;
    if (remaining == 0) { ans.push_back(cur); return; }
    cur.push_back(a[idx]);
    dfs(idx, remaining - a[idx], a, cur, ans);  // reuse allowed (stay at idx)
    cur.pop_back();
    dfs(idx + 1, remaining, a, cur, ans);       // move on (idx+1)
}`,
    python: `def dfs(idx, remaining, cur):
    if remaining < 0 or idx == len(a):
        return
    if remaining == 0:
        ans.append(cur[:])
        return
    cur.append(a[idx])
    dfs(idx, remaining - a[idx], cur)   # reuse allowed
    cur.pop()
    dfs(idx + 1, remaining, cur)        # move on`,
    java: `void dfs(int idx, int remaining, int[] a, List<Integer> cur, List<List<Integer>> ans) {
    if (idx == a.length || remaining < 0) return;
    if (remaining == 0) { ans.add(new ArrayList<>(cur)); return; }
    cur.add(a[idx]);
    dfs(idx, remaining - a[idx], a, cur, ans);
    cur.remove(cur.size() - 1);
    dfs(idx + 1, remaining, a, cur, ans);
}`
  },
  problems: L([
    ['Combination Sum','https://leetcode.com/problems/combination-sum/','Medium'],
    ['Combination Sum II','https://leetcode.com/problems/combination-sum-ii/','Medium'],
    ['Combination Sum III','https://leetcode.com/problems/combination-sum-iii/','Medium']
  ]),
  pitfalls: ['Stay at idx for reuse; move to idx+1 to avoid duplicate combinations (I vs II).', 'For Combination Sum II (duplicates allowed in input): sort + skip equal values at the same loop level.']
},
{
  topic: 'Recursion & Backtracking', name: 'Grid / Board Backtracking (N-Queens, Word Search)', what: 'DFS over cells with an explicit "undo" of the state after each attempt.', when: 'N-Queens, Sudoku, Word Search, Rat in a Maze, palindrome partitioning.', tc: 'Exponential (pruning matters)', sc: 'O(depth)',
  template: {
    cpp: `bool solve(vector<vector<char>>& board, int r, int c, string& word, int i) {
    if (i == (int)word.size()) return true;
    if (r < 0 || c < 0 || r >= (int)board.size() || c >= (int)board[0].size()
        || board[r][c] != word[i]) return false;
    char keep = board[r][c];
    board[r][c] = '#';                       // mark visited
    bool found = solve(board, r+1, c, word, i+1) || solve(board, r-1, c, word, i+1)
              || solve(board, r, c+1, word, i+1) || solve(board, r, c-1, word, i+1);
    board[r][c] = keep;                      // un-mark (backtrack)
    return found;
}`,
    python: `def solve(r, c, i):
    if i == len(word): return True
    if r < 0 or c < 0 or r >= len(board) or c >= len(board[0]) or board[r][c] != word[i]:
        return False
    keep = board[r][c]
    board[r][c] = '#'                       # mark
    found = any(solve(r + dr, c + dc, i + 1) for dr, dc in ((1,0),(-1,0),(0,1),(0,-1)))
    board[r][c] = keep                      # un-mark
    return found`,
    java: `boolean solve(int r, int c, int i, char[][] b, String word) {
    if (i == word.length()) return true;
    if (r < 0 || c < 0 || r >= b.length || c >= b[0].length || b[r][c] != word.charAt(i))
        return false;
    char keep = b[r][c];
    b[r][c] = '#';
    boolean found = solve(r+1,c,i+1,b,word) || solve(r-1,c,i+1,b,word)
                 || solve(r,c+1,i+1,b,word) || solve(r,c-1,i+1,b,word);
    b[r][c] = keep;
    return found;
}`
  },
  problems: L([
    ['Word Search','https://leetcode.com/problems/word-search/','Medium'],
    ['N-Queens','https://leetcode.com/problems/n-queens/','Hard'],
    ['Rat in a Maze (GFG)','https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1','Medium'],
    ['Palindrome Partitioning','https://leetcode.com/problems/palindrome-partitioning/','Medium']
  ]),
  pitfalls: ['Mark → recurse → unmark; forgetting the unmark poisons later paths.', 'N-Queens: track occupied columns and both diagonals (r−c and r+c) as boolean sets for fast pruning.']
},

/* ============ LINKED LIST ============ */
{
  topic: 'Linked List', name: 'Fast & Slow Pointers (Floyd\'s Cycle)', what: 'Two pointers, one moving 2× the other: finds the middle, detects cycles, and finds the cycle start.', when: 'Middle of list, cycle detection/start, happy number, find duplicate number (array as implicit list).', tc: 'O(n)', sc: 'O(1)',
  template: {
    cpp: `// middle of linked list
ListNode *slow = head, *fast = head;
while (fast && fast->next) { slow = slow->next; fast = fast->next->next; }
// slow = middle

// cycle detection + start of cycle
if (slow == fast) {
    slow = head;                            // move one to head
    while (slow != fast) { slow = slow->next; fast = fast->next; }
    return slow;                            // cycle start node
}`,
    python: `slow = fast = head
while fast and fast.next:
    slow = slow.next
    fast = fast.next.next
    if slow is fast:            # cycle found
        slow = head
        while slow is not fast:
            slow = slow.next
            fast = fast.next
        return slow             # cycle start
# if loop ends: slow is the middle`,
    java: `ListNode slow = head, fast = head;
while (fast != null && fast.next != null) {
    slow = slow.next;
    fast = fast.next.next;
    if (slow == fast) {          // cycle
        slow = head;
        while (slow != fast) { slow = slow.next; fast = fast.next; }
        return slow;             // cycle start
    }
}
return slow; // middle`
  },
  problems: L([
    ['Linked List Cycle','https://leetcode.com/problems/linked-list-cycle/','Easy'],
    ['Linked List Cycle II','https://leetcode.com/problems/linked-list-cycle-ii/','Medium'],
    ['Middle of the Linked List','https://leetcode.com/problems/middle-of-the-linked-list/','Easy'],
    ['Find the Duplicate Number','https://leetcode.com/problems/find-the-duplicate-number/','Medium']
  ]),
  pitfalls: ['Middle: with fast/slow from head, slow lands at the FIRST middle for even length — check which the problem wants.', 'Cycle start proof: after meeting, reset one pointer to head; equal steps meet at the entry (a = c).', 'Always check fast.next before fast.next.next to avoid null dereference.']
},
{
  topic: 'Linked List', name: 'In-Place Reversal (Full / Partial / K-Group)', what: 'Rewire next pointers iteratively with prev/cur/nxt; the same core handles sublists and k-groups.', when: 'Reverse list, reverse II (interval), reverse k-group, rotate list, palindrome check (reverse second half).', tc: 'O(n)', sc: 'O(1)',
  template: {
    cpp: `// reverse whole list
ListNode* prev = nullptr, *cur = head;
while (cur) {
    ListNode* nxt = cur->next;
    cur->next = prev;
    prev = cur;
    cur = nxt;
}
// prev = new head

// reverse nodes [left..right] (1-indexed): walk to left-1, keep the node
// before the segment (nodePrev) and the first node inside (tail=leftNode);
// reverse (right-left+1) nodes; then nodePrev->next = newHead, tail->next = after.`,
    python: `prev, cur = None, head
while cur:
    nxt = cur.next
    cur.next = prev
    prev = cur
    cur = nxt
# prev is the new head`,
    java: `ListNode prev = null, cur = head;
while (cur != null) {
    ListNode nxt = cur.next;
    cur.next = prev;
    prev = cur;
    cur = nxt;
}
// prev = new head`
  },
  problems: L([
    ['Reverse Linked List','https://leetcode.com/problems/reverse-linked-list/','Easy'],
    ['Reverse Linked List II','https://leetcode.com/problems/reverse-linked-list-ii/','Medium'],
    ['Reverse Nodes in k-Group','https://leetcode.com/problems/reverse-nodes-in-k-group/','Hard'],
    ['Palindrome Linked List','https://leetcode.com/problems/palindrome-linked-list/','Easy']
  ]),
  pitfalls: ['Always save nxt BEFORE rewiring cur->next.', 'Use a dummy node to handle "reverse from head" uniformly.', 'For k-group: check you have k nodes left before starting a segment.']
},
{
  topic: 'Linked List', name: 'Merge Two / K Sorted Lists', what: 'Merge with a dummy head (two lists) or repeatedly merge / use a min-heap over list heads (K lists).', when: 'Merge sorted lists, merge sort on lists, smallest range from K lists.', tc: 'O(n+m) two lists; O(N log K) K lists', sc: 'O(1) (pointer merge)',
  template: {
    cpp: `// two sorted lists — dummy head trick
ListNode dummy; ListNode* tail = &dummy;
while (l1 && l2) {
    if (l1->val <= l2->val) { tail->next = l1; l1 = l1->next; }
    else                    { tail->next = l2; l2 = l2->next; }
    tail = tail->next;
}
tail->next = l1 ? l1 : l2;
return dummy.next;

// K lists: push each head into min-heap; pop smallest, append, push its next`,
    python: `dummy = tail = ListNode()
while l1 and l2:
    if l1.val <= l2.val:
        tail.next, l1 = l1, l1.next
    else:
        tail.next, l2 = l2, l2.next
    tail = tail.next
tail.next = l1 or l2
return dummy.next

# K lists:
# heap = [(node.val, i, node) for i, node in enumerate(lists) if node]
# heapify(heap); pop smallest, append to tail, push node.next`,
    java: `ListNode dummy = new ListNode(), tail = dummy;
while (l1 != null && l2 != null) {
    if (l1.val <= l2.val) { tail.next = l1; l1 = l1.next; }
    else { tail.next = l2; l2 = l2.next; }
    tail = tail.next;
}
tail.next = (l1 != null) ? l1 : l2;
return dummy.next;`
  },
  problems: L([
    ['Merge Two Sorted Lists','https://leetcode.com/problems/merge-two-sorted-lists/','Easy'],
    ['Merge k Sorted Lists','https://leetcode.com/problems/merge-k-sorted-lists/','Hard'],
    ['Sort List','https://leetcode.com/problems/sort-list/','Medium']
  ]),
  pitfalls: ['The dummy node removes every "is it the head?" special case.', 'In the heap for K lists, store (value, list index, node) to break ties safely (Python can\'t compare nodes).']
},
{
  topic: 'Linked List', name: 'Doubly Linked List + HashMap (LRU / MRU)', what: 'HashMap: key → node; DLL ordered by recency. Both operations O(1) by unlinking/relinking nodes.', when: 'LRU Cache, LFU, first-unique maintenance, "design" problems requiring O(1) move/remove.', tc: 'O(1) per op', sc: 'O(capacity)',
  template: {
    cpp: `// nodes have prev/next; head & tail are sentinels
void remove(Node* n) { n->prev->next = n->next; n->next->prev = n->prev; }
void pushFront(Node* n) { n->next = head->next; n->prev = head;
                          head->next->prev = n; head->next = n; }
int get(int key) { if (!m.count(key)) return -1;
    Node* n = m[key]; remove(n); pushFront(n); return n->val; }
void put(int key, int val) {
    if (m.count(key)) { m[key]->val = val; remove(m[key]); pushFront(m[key]); return; }
    if ((int)m.size() == cap) { Node* lru = tail->prev; remove(lru); m.erase(lru->key); }
    Node* n = new Node(key, val); m[key] = n; pushFront(n);
}`,
    python: `class Node:
    def __init__(self, k=0, v=0): self.k, self.v = k, v; self.prev = self.next = None

# head/tail sentinels; self.m = {}
def _remove(n): n.prev.next, n.next.prev = n.next, n.prev
def _push_front(n):
    n.next, n.prev = head.next, head
    head.next.prev = n; head.next = n
# get: if k in m: remove; push_front; return value
# put: update or evict tail.prev when full`,
    java: `class Node { int k, v; Node prev, next; }
// head/tail sentinels, Map<Integer,Node> m
void remove(Node n) { n.prev.next = n.next; n.next.prev = n.prev; }
void pushFront(Node n) {
    n.next = head.next; n.prev = head;
    head.next.prev = n; head.next = n;
}
// get/put as in C++: move-to-front on access, evict tail.prev on overflow`
  },
  problems: L([
    ['LRU Cache','https://leetcode.com/problems/lru-cache/','Medium'],
    ['LFU Cache','https://leetcode.com/problems/lfu-cache/','Hard'],
    ['Design Twitter','https://leetcode.com/problems/design-twitter/','Medium']
  ]),
  pitfalls: ['Sentinel head/tail nodes remove all edge cases.', 'Update the map when you evict — forgetting erase(key) is the classic bug.', 'In Python use collections.OrderedDict(move_to_end / popitem) for a short version.']
},

/* ============ STACK & QUEUE ============ */
{
  topic: 'Stack & Queue', name: 'Implement Stack / Queue From Scratch', what: 'Stack via array + top index (or deque); queue via circular array or amortized two stacks.', when: 'Design problems, understanding amortized analysis, "implement X without built-ins".', tc: 'O(1) per op (amortized for two-stack queue)', sc: 'O(n)',
  template: {
    cpp: `// queue using two stacks — amortized O(1)
stack<int> in, out;
void push(int x) { in.push(x); }
int pop() {
    if (out.empty())
        while (!in.empty()) { out.push(in.top()); in.pop(); }
    int v = out.top(); out.pop(); return v;
}
bool empty() { return in.empty() && out.empty(); }`,
    python: `class MyQueue:
    def __init__(self):
        self.inbox, self.out = [], []
    def push(self, x):
        self.inbox.append(x)
    def pop(self):
        if not self.out:
            while self.inbox:
                self.out.append(self.inbox.pop())
        return self.out.pop()
    def empty(self):
        return not self.inbox and not self.out`,
    java: `Deque<Integer> in = new ArrayDeque<>(), out = new ArrayDeque<>();
void push(int x) { in.push(x); }
int pop() {
    if (out.isEmpty())
        while (!in.isEmpty()) out.push(in.pop());
    return out.pop();
}
boolean empty() { return in.isEmpty() && out.isEmpty(); }`
  },
  problems: L([
    ['Valid Parentheses','https://leetcode.com/problems/valid-parentheses/','Easy'],
    ['Implement Queue using Stacks','https://leetcode.com/problems/implement-queue-using-stacks/','Easy'],
    ['Min Stack','https://leetcode.com/problems/min-stack/','Medium'],
    ['Implement Stack using Queues','https://leetcode.com/problems/implement-stack-using-queues/','Easy']
  ]),
  pitfalls: ['Min Stack: keep a second stack of "min so far" — push the old min when it would be lost.', 'Transfer stacks only when out is empty, otherwise order breaks.']
},
{
  topic: 'Stack & Queue', name: 'Expression Parsing (Infix ↔ Postfix, Evaluation)', what: 'Shunting-yard: operators to a stack by precedence, operands straight to output; evaluate postfix with a value stack.', when: 'Infix to postfix, basic calculator, decode string, evaluate reverse polish notation.', tc: 'O(n)', sc: 'O(n)',
  template: {
    cpp: `int prec(char c) { return c=='^' ? 3 : (c=='*' || c=='/') ? 2 : (c=='+' || c=='-') ? 1 : 0; }
string infixToPostfix(string s) {
    string out; stack<char> st;
    for (char c : s) {
        if (isalnum((unsigned char)c)) out += c;
        else if (c == '(') st.push(c);
        else if (c == ')') { while (st.top() != '(') { out += st.top(); st.pop(); } st.pop(); }
        else { while (!st.empty() && prec(st.top()) >= prec(c)) { out += st.top(); st.pop(); } st.push(c); }
    }
    while (!st.empty()) { out += st.top(); st.pop(); }
    return out;
}`,
    python: `def prec(c): return {'+':1, '-':1, '*':2, '/':2, '^':3}.get(c, 0)
def infix_to_postfix(s):
    out, st = [], []
    for c in s:
        if c.isalnum(): out.append(c)
        elif c == '(': st.append(c)
        elif c == ')':
            while st[-1] != '(': out.append(st.pop())
            st.pop()
        else:
            while st and prec(st[-1]) >= prec(c): out.append(st.pop())
            st.append(c)
    while st: out.append(st.pop())
    return ''.join(out)`,
    java: `int prec(char c) { return switch (c) { case '^' -> 3; case '*', '/' -> 2; case '+', '-' -> 1; default -> 0; }; }
String infixToPostfix(String s) {
    StringBuilder out = new StringBuilder();
    Deque<Character> st = new ArrayDeque<>();
    for (char c : s.toCharArray()) {
        if (Character.isLetterOrDigit(c)) out.append(c);
        else if (c == '(') st.push(c);
        else if (c == ')') { while (st.peek() != '(') out.append(st.pop()); st.pop(); }
        else { while (!st.isEmpty() && prec(st.peek()) >= prec(c)) out.append(st.pop()); st.push(c); }
    }
    while (!st.isEmpty()) out.append(st.pop());
    return out.toString();
}`
  },
  problems: L([
    ['Infix to Postfix (GFG)','https://www.geeksforgeeks.org/problems/infix-to-postfix-1587115620/1','Medium'],
    ['Basic Calculator','https://leetcode.com/problems/basic-calculator/','Hard'],
    ['Evaluate Reverse Polish Notation','https://leetcode.com/problems/evaluate-reverse-polish-notation/','Medium'],
    ['Decode String','https://leetcode.com/problems/decode-string/','Medium']
  ]),
  pitfalls: ['Only pop operators with HIGHER-or-equal precedence (left-assoc); for ^ (right-assoc) use strictly greater.', 'Beware stack.top() on an empty stack when input has unbalanced parentheses.']
},

/* ============ MONOTONIC STACK ============ */
{
  topic: 'Monotonic Stack', name: 'Monotonic Stack (Next Greater / Smaller Element)', what: 'Keep a stack whose values are increasing (or decreasing); each element is pushed/popped at most once.', when: 'Next greater/smaller element (both sides), daily temperatures, stock span, largest rectangle in histogram, trapping rain (stack way).', tc: 'O(n)', sc: 'O(n)',
  template: {
    cpp: `// next greater element to the right (index or -1)
vector<int> nge(n);
stack<int> st;                    // indices, values strictly decreasing
for (int i = n - 1; i >= 0; i--) {
    while (!st.empty() && a[st.top()] <= a[i]) st.pop();
    nge[i] = st.empty() ? -1 : st.top();
    st.push(i);
}
// For "previous greater": iterate left→right with the same pattern.
// For next SMALLER: flip the comparison to >=.`,
    python: `nge = [-1] * n
st = []                    # indices, values strictly decreasing
for i in range(n - 1, -1, -1):
    while st and a[st[-1]] <= a[i]:
        st.pop()
    nge[i] = st[-1] if st else -1
    st.append(i)`,
    java: `int[] nge = new int[n];
Deque<Integer> st = new ArrayDeque<>();   // indices, values strictly decreasing
for (int i = n - 1; i >= 0; i--) {
    while (!st.isEmpty() && a[st.peek()] <= a[i]) st.pop();
    nge[i] = st.isEmpty() ? -1 : st.peek();
    st.push(i);
}`
  },
  problems: L([
    ['Next Greater Element I','https://leetcode.com/problems/next-greater-element-i/','Easy'],
    ['Daily Temperatures','https://leetcode.com/problems/daily-temperatures/','Medium'],
    ['Largest Rectangle in Histogram','https://leetcode.com/problems/largest-rectangle-in-histogram/','Hard'],
    ['Sum of Subarray Minimums','https://leetcode.com/problems/sum-of-subarray-minimums/','Medium']
  ]),
  pitfalls: ['<= vs < decides whether equal elements count — for Sum of Subarray Minimums use strict on one side, non-strict on the other to avoid double counting.', 'Largest rectangle: when popping, the width is i − st.top() − 1 (or i if empty); append a sentinel 0 at the end to flush.', 'The stack stores indices, not values — you need indices for widths.']
},

/* ============ HEAP / PRIORITY QUEUE ============ */
{
  topic: 'Heap / Priority Queue', name: 'Top-K Elements (Size-K Min-Heap)', what: 'Keep a min-heap of size k while scanning; the heap ends holding the k largest.', when: '"K largest/smallest", "K closest", "K frequent", streaming top-k where n >> k.', tc: 'O(n log k)', sc: 'O(k)',
  template: {
    cpp: `priority_queue<int, vector<int>, greater<int>> minh;   // min-heap of size k
for (int x : nums) {
    minh.push(x);
    if ((int)minh.size() > k) minh.pop();   // evict smallest
}
// minh now holds the k largest elements`,
    python: `import heapq
minh = []                       # min-heap of size k
for x in nums:
    heapq.heappush(minh, x)
    if len(minh) > k:
        heapq.heappop(minh)
# minh now holds the k largest
# top-k largest directly: heapq.nlargest(k, nums)`,
    java: `PriorityQueue<Integer> minh = new PriorityQueue<>();  // min-heap
for (int x : nums) {
    minh.offer(x);
    if (minh.size() > k) minh.poll();
}
// minh holds the k largest`
  },
  problems: L([
    ['Kth Largest Element in an Array','https://leetcode.com/problems/kth-largest-element-in-an-array/','Medium'],
    ['Top K Frequent Elements','https://leetcode.com/problems/top-k-frequent-elements/','Medium'],
    ['K Closest Points to Origin','https://leetcode.com/problems/k-closest-points-to-origin/','Medium'],
    ['Kth Largest Element in a Stream','https://leetcode.com/problems/kth-largest-element-in-a-stream/','Easy']
  ]),
  pitfalls: ['For k LARGEST you keep a MIN-heap (pop the smallest); counterintuitive but correct.', 'For k SMALLEST, keep a max-heap (or negate values in Python).', 'Alternative: quickselect gives average O(n) if order isn\'t needed.']
},
{
  topic: 'Heap / Priority Queue', name: 'Two Heaps (Running Median)', what: 'Max-heap holds the smaller half, min-heap the larger half; rebalance so sizes differ by ≤ 1.', when: 'Running/streaming median, sliding-window median, "balance two halves" designs.', tc: 'O(log n) per add', sc: 'O(n)',
  template: {
    cpp: `priority_queue<int> low;                             // max-heap (smaller half)
priority_queue<int, vector<int>, greater<int>> high; // min-heap (larger half)
void addNum(int x) {
    if (low.empty() || x <= low.top()) low.push(x);
    else high.push(x);
    if (low.size() > high.size() + 1) { high.push(low.top()); low.pop(); }
    else if (high.size() > low.size()) { low.push(high.top()); high.pop(); }
}
double median() {
    if (low.size() > high.size()) return low.top();
    return (low.top() + high.top()) / 2.0;
}`,
    python: `import heapq
low, high = [], []     # low = max-heap (negated), high = min-heap
def add(x):
    if not low or x <= -low[0]:
        heapq.heappush(low, -x)
    else:
        heapq.heappush(high, x)
    if len(low) > len(high) + 1:
        heapq.heappush(high, -heapq.heappop(low))
    elif len(high) > len(low):
        heapq.heappush(low, -heapq.heappop(high))
def median():
    return -low[0] if len(low) > len(high) else (-low[0] + high[0]) / 2`,
    java: `PriorityQueue<Integer> low = new PriorityQueue<>(Collections.reverseOrder());
PriorityQueue<Integer> high = new PriorityQueue<>();
void add(int x) {
    if (low.isEmpty() || x <= low.peek()) low.offer(x); else high.offer(x);
    if (low.size() > high.size() + 1) high.offer(low.poll());
    else if (high.size() > low.size()) low.offer(high.poll());
}
double median() {
    return low.size() > high.size() ? low.peek() : (low.peek() + high.peek()) / 2.0;
}`
  },
  problems: L([
    ['Find Median from Data Stream','https://leetcode.com/problems/find-median-from-data-stream/','Hard'],
    ['Sliding Window Median','https://leetcode.com/problems/sliding-window-median/','Hard'],
    ['IPO','https://leetcode.com/problems/ipo/','Hard']
  ]),
  pitfalls: ['Python has no max-heap — store negatives in the min-heap.', 'Rebalance on EVERY insertion, not at query time.', 'Median of two even halves needs the average — watch integer division.']
},
{
  topic: 'Heap / Priority Queue', name: 'K-Way Merge', what: 'Merge K sorted streams: keep the current head of each in a min-heap; pop the smallest, advance that stream.', when: 'Merge K sorted lists/arrays, smallest range covering K lists, sorted matrix visits.', tc: 'O(N log K)', sc: 'O(K)',
  template: {
    cpp: `struct Item { int val, i, j; };                  // val, list i, index j
priority_queue<Item, vector<Item>, greater<Item>> pq;  // min-heap by val
for (int i = 0; i < K; i++) pq.push({arr[i][0], i, 0});
vector<int> out;
while (!pq.empty()) {
    auto [v, i, j] = pq.top(); pq.pop();
    out.push_back(v);
    if (j + 1 < (int)arr[i].size()) pq.push({arr[i][j+1], i, j+1});
}`,
    python: `import heapq
pq = [(row[0], i, 0) for i, row in enumerate(rows) if row]
heapq.heapify(pq)
out = []
while pq:
    v, i, j = heapq.heappop(pq)
    out.append(v)
    if j + 1 < len(rows[i]):
        heapq.heappush(pq, (rows[i][j+1], i, j + 1))`,
    java: `PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] - b[0]); // val, i, j
for (int i = 0; i < k; i++) if (arr[i].length > 0) pq.offer(new int[]{arr[i][0], i, 0});
List<Integer> out = new ArrayList<>();
while (!pq.isEmpty()) {
    int[] t = pq.poll(); int v = t[0], i = t[1], j = t[2];
    out.add(v);
    if (j + 1 < arr[i].length) pq.offer(new int[]{arr[i][j+1], i, j + 1});
}`
  },
  problems: L([
    ['Merge k Sorted Lists','https://leetcode.com/problems/merge-k-sorted-lists/','Hard'],
    ['Smallest Range Covering Elements from K Lists','https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/','Hard'],
    ['Find K Pairs with Smallest Sums','https://leetcode.com/problems/find-k-pairs-with-smallest-sums/','Medium']
  ]),
  pitfalls: ['Tie-breaking: include a list index in the heap key so comparisons never fall through to node pointers.', 'Lazy deletion variant: push duplicates and skip already-visited values.']
},

/* ============ TREES & BST ============ */
{
  topic: 'Trees & BST', name: 'Tree Traversals (Pre/In/Post + Level)', what: 'DFS orders (pre/in/post) recursively or with a stack; level order with a queue.', when: 'Almost every tree problem starts here: BST sorted output = inorder, serialization, right-side view = last of each level.', tc: 'O(n)', sc: 'O(h) stack / O(w) queue',
  template: {
    cpp: `// recursive inorder: left, node, right (pre: node,left,right / post: left,right,node)
void inorder(Node* r, vector<int>& out) {
    if (!r) return;
    inorder(r->left, out);
    out.push_back(r->val);
    inorder(r->right, out);
}
// level order (BFS)
queue<Node*> q; q.push(root);
while (!q.empty()) {
    int sz = q.size();                    // nodes of the current level
    vector<int> level;
    for (int i = 0; i < sz; i++) {
        Node* n = q.front(); q.pop();
        level.push_back(n->val);
        if (n->left) q.push(n->left);
        if (n->right) q.push(n->right);
    }
    // process 'level'
}`,
    python: `def inorder(r, out):
    if not r: return
    inorder(r.left, out)
    out.append(r.val)
    inorder(r.right, out)

# level order
from collections import deque
q = deque([root])
while q:
    level = []
    for _ in range(len(q)):
        n = q.popleft()
        level.append(n.val)
        if n.left: q.append(n.left)
        if n.right: q.append(n.right)
    # process level`,
    java: `void inorder(Node r, List<Integer> out) {
    if (r == null) return;
    inorder(r.left, out);
    out.add(r.val);
    inorder(r.right, out);
}
// level order
Queue<Node> q = new ArrayDeque<>();
q.offer(root);
while (!q.isEmpty()) {
    int sz = q.size();
    List<Integer> level = new ArrayList<>();
    for (int i = 0; i < sz; i++) {
        Node n = q.poll();
        level.add(n.val);
        if (n.left != null) q.offer(n.left);
        if (n.right != null) q.offer(n.right);
    }
}`
  },
  problems: L([
    ['Binary Tree Inorder Traversal','https://leetcode.com/problems/binary-tree-inorder-traversal/','Easy'],
    ['Binary Tree Level Order Traversal','https://leetcode.com/problems/binary-tree-level-order-traversal/','Medium'],
    ['Binary Tree Right Side View','https://leetcode.com/problems/binary-tree-right-side-view/','Medium'],
    ['Maximum Depth of Binary Tree','https://leetcode.com/problems/maximum-depth-of-binary-tree/','Easy']
  ]),
  pitfalls: ['Level-size trick: iterate exactly q.size() times per level, captured BEFORE pushing children.', 'Iterative inorder: push left spine, pop, go right.', 'Zigzag = level order + reverse odd levels.']
},
{
  topic: 'Trees & BST', name: 'BST Operations (Search, Insert, Delete, Floor/Ceil)', what: 'BST invariant: left subtree < node < right subtree — every op branches one way, O(h).', when: 'Search/insert/delete in BST, floor/ceil, kth smallest (inorder count), range sum.', tc: 'O(h) → O(log n) balanced, O(n) skewed', sc: 'O(1) iterative / O(h) recursive',
  template: {
    cpp: `Node* search(Node* r, int x) {
    while (r && r->val != x) r = x < r->val ? r->left : r->right;
    return r;
}
Node* insert(Node* r, int x) {
    if (!r) return new Node(x);
    if (x < r->val) r->left = insert(r->left, x);
    else            r->right = insert(r->right, x);
    return r;
}
Node* del(Node* r, int x) {
    if (!r) return nullptr;
    if (x < r->val) r->left = del(r->left, x);
    else if (x > r->val) r->right = del(r->right, x);
    else {
        if (!r->left)  return r->right;
        if (!r->right) return r->left;
        Node* s = r->right;                 // inorder successor
        while (s->left) s = s->left;
        r->val = s->val;
        r->right = del(r->right, s->val);
    }
    return r;
}`,
    python: `def search(r, x):
    while r and r.val != x:
        r = r.left if x < r.val else r.right
    return r

def insert(r, x):
    if not r: return Node(x)
    if x < r.val: r.left = insert(r.left, x)
    else:         r.right = insert(r.right, x)
    return r`,
    java: `Node search(Node r, int x) {
    while (r != null && r.val != x) r = x < r.val ? r.left : r.right;
    return r;
}
Node insert(Node r, int x) {
    if (r == null) return new Node(x);
    if (x < r.val) r.left = insert(r.left, x);
    else r.right = insert(r.right, x);
    return r;
}`
  },
  problems: L([
    ['Search in a Binary Search Tree','https://leetcode.com/problems/search-in-a-binary-search-tree/','Easy'],
    ['Delete Node in a BST','https://leetcode.com/problems/delete-node-in-a-bst/','Medium'],
    ['Kth Smallest Element in a BST','https://leetcode.com/problems/kth-smallest-element-in-a-bst/','Medium'],
    ['Floor / Ceil in BST (GFG)','https://www.geeksforgeeks.org/problems/implementing-ceil-in-bst/1','Easy']
  ]),
  pitfalls: ['Delete with two children: replace with inorder successor (min of right subtree), then delete that successor.', 'kth smallest = inorder traversal stopped at k — O(h+k).', 'Skewed BST = linked list; balanced guarantee only for AVL/red-black.']
},
{
  topic: 'Trees & BST', name: 'LCA (Binary Tree & BST)', what: 'LCA is the deepest node whose subtree contains both targets; in a BST you can navigate by value comparison.', when: 'Lowest common ancestor, distance between nodes, "both nodes in one subtree" splits.', tc: 'O(n) general / O(h) BST', sc: 'O(h)',
  template: {
    cpp: `// general binary tree
Node* lca(Node* r, Node* p, Node* q) {
    if (!r || r == p || r == q) return r;
    Node* L = lca(r->left, p, q);
    Node* R = lca(r->right, p, q);
    if (L && R) return r;          // split point
    return L ? L : R;
}
// BST version — navigate by value
Node* lcaBst(Node* r, Node* p, Node* q) {
    while (r) {
        if (p->val < r->val && q->val < r->val) r = r->left;
        else if (p->val > r->val && q->val > r->val) r = r->right;
        else return r;
    }
    return nullptr;
}`,
    python: `def lca(r, p, q):
    if not r or r is p or r is q: return r
    L, R = lca(r.left, p, q), lca(r.right, p, q)
    if L and R: return r           # split point
    return L or R

def lca_bst(r, p, q):
    while r:
        if p.val < r.val and q.val < r.val: r = r.left
        elif p.val > r.val and q.val > r.val: r = r.right
        else: return r`,
    java: `Node lca(Node r, Node p, Node q) {
    if (r == null || r == p || r == q) return r;
    Node L = lca(r.left, p, q), R = lca(r.right, p, q);
    if (L != null && R != null) return r;
    return L != null ? L : R;
}
Node lcaBst(Node r, Node p, Node q) {
    while (r != null) {
        if (p.val < r.val && q.val < r.val) r = r.left;
        else if (p.val > r.val && q.val > r.val) r = r.right;
        else return r;
    }
    return null;
}`
  },
  problems: L([
    ['Lowest Common Ancestor of a Binary Tree','https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/','Medium'],
    ['Lowest Common Ancestor of a BST','https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/','Easy'],
    ['Maximum Distance Between Nodes (via LCA)','https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/','Medium']
  ]),
  pitfalls: ['The general version returns the split point; a node may be an ancestor of itself — check problem wording.', 'BST LCA: the first node BETWEEN p.val and q.val is the answer.']
},
{
  topic: 'Trees & BST', name: 'Tree Construction from Traversals', what: 'First (preorder) or last (postorder) element is the root; inorder splits left/right subtrees — recurse with index maps.', when: 'Build tree from pre+in, post+in, preorder+ BST property (upper bound trick).', tc: 'O(n)', sc: 'O(n)',
  template: {
    cpp: `unordered_map<int,int> pos;                 // value -> inorder index
Node* build(vector<int>& pre, int pl, int pr, int il, int ir) {
    if (pl > pr) return nullptr;
    Node* r = new Node(pre[pl]);            // first preorder = root
    int k = pos[r->val];                    // split point in inorder
    int leftSz = k - il;
    r->left  = build(pre, pl+1, pl+leftSz, il, k-1);
    r->right = build(pre, pl+leftSz+1, pr, k+1, ir);
    return r;
}
// build(pre, 0, n-1, 0, n-1) with pos filled from inorder`,
    python: `pos = {}
def build(pre, pl, pr, il, ir):
    if pl > pr: return None
    r = TreeNode(pre[pl])
    k = pos[r.val]
    left = k - il
    r.left = build(pre, pl + 1, pl + left, il, k - 1)
    r.right = build(pre, pl + left + 1, pr, k + 1, ir)
    return r`,
    java: `Map<Integer, Integer> pos = new HashMap<>();
Node build(int[] pre, int pl, int pr, int il, int ir) {
    if (pl > pr) return null;
    Node r = new Node(pre[pl]);
    int k = pos.get(r.val);
    int left = k - il;
    r.left = build(pre, pl + 1, pl + left, il, k - 1);
    r.right = build(pre, pl + left + 1, pr, k + 1, ir);
    return r;
}`
  },
  problems: L([
    ['Construct Binary Tree from Preorder and Inorder','https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/','Medium'],
    ['Construct Binary Tree from Inorder and Postorder','https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/','Medium'],
    ['Construct BST from Preorder','https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/','Medium']
  ]),
  pitfalls: ['Precompute the inorder index map — searching per node is O(n²).', 'preorder+postorder can\'t uniquely rebuild trees with duplicate values.', 'BST from preorder: recurse with (lower, upper) bounds, no inorder needed.']
},
{
  topic: 'Trees & BST', name: 'Views & Level-Based Problems', what: 'Top/bottom views: BFS with horizontal distance + map; left/right view: first/last node per level.', when: 'Top/bottom/left/right view, vertical order traversal, burning tree (BFS from target + parent map).', tc: 'O(n)', sc: 'O(n)',
  template: {
    cpp: `// top view — BFS with column index
queue<pair<Node*,int>> q; q.push({root, 0});
map<int,int> seen;                       // column -> first seen value
while (!q.empty()) {
    auto [n, c] = q.front(); q.pop();
    if (!seen.count(c)) seen[c] = n->val; // top view: only first visit
    if (n->left)  q.push({n->left,  c-1});
    if (n->right) q.push({n->right, c+1});
}
// bottom view: unconditional seen[c] = n->val (last wins)`,
    python: `from collections import deque
q = deque([(root, 0)])
seen = {}                       # column -> value
while q:
    n, c = q.popleft()
    if c not in seen:
        seen[c] = n.val         # top view; bottom view: assign unconditionally
    if n.left: q.append((n.left, c - 1))
    if n.right: q.append((n.right, c + 1))
out = [seen[k] for k in sorted(seen)]`,
    java: `Queue<Object[]> q = new ArrayDeque<>(); q.offer(new Object[]{root, 0});
TreeMap<Integer, Integer> seen = new TreeMap<>();
while (!q.isEmpty()) {
    Object[] t = q.poll(); Node n = (Node) t[0]; int c = (int) t[1];
    seen.putIfAbsent(c, n.val);        // top view
    if (n.left != null) q.offer(new Object[]{n.left, c - 1});
    if (n.right != null) q.offer(new Object[]{n.right, c + 1});
}`
  },
  problems: L([
    ['Top View of Binary Tree (GFG)','https://www.geeksforgeeks.org/problems/top-view-of-binary-tree/1','Medium'],
    ['Bottom View of Binary Tree (GFG)','https://www.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1','Medium'],
    ['Vertical Order Traversal','https://leetcode.com/problems/vertical-order-traversal/','Hard'],
    ['Amount of Time for Binary Tree to Be Infected','https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/','Medium']
  ]),
  pitfalls: ['Use a map keyed by column so output stays sorted left→right.', 'Burning tree: build a parent-pointer map, then BFS from the target — fire spreads to parent + children.', 'Vertical order LC 987 needs (column, row) sorting — plain GFG top view does not.']
},

/* ============ TRIES ============ */
{
  topic: 'Tries', name: 'Trie (Prefix Tree)', what: 'Tree of characters where each node maps to children; words sharing prefixes share paths.', when: 'Prefix search, autocomplete, word dictionary with wildcards, XOR maximization (binary trie), word search on boards.', tc: 'O(L) per insert/search', sc: 'O(total characters × alphabet)',
  template: {
    cpp: `struct Trie {
    Trie* ch[26] = {};
    bool isEnd = false;
    void insert(const string& w) {
        Trie* n = this;
        for (char c : w) {
            int i = c - 'a';
            if (!n->ch[i]) n->ch[i] = new Trie();
            n = n->ch[i];
        }
        n->isEnd = true;
    }
    bool search(const string& w) {
        Trie* n = this;
        for (char c : w) {
            if (!n->ch[c-'a']) return false;
            n = n->ch[c-'a'];
        }
        return n->isEnd;
    }
    bool startsWith(const string& p) {
        Trie* n = this;
        for (char c : p) {
            if (!n->ch[c-'a']) return false;
            n = n->ch[c-'a'];
        }
        return true;
    }
};`,
    python: `class Trie:
    def __init__(self):
        self.ch = {}
        self.is_end = False
    def insert(self, w):
        n = self
        for c in w:
            n = n.ch.setdefault(c, Trie())
        n.is_end = True
    def search(self, w):
        n = self._find(w)
        return n is not None and n.is_end
    def starts_with(self, p):
        return self._find(p) is not None
    def _find(self, s):
        n = self
        for c in s:
            if c not in n.ch: return None
            n = n.ch[c]
        return n`,
    java: `class Trie {
    Trie[] ch = new Trie[26];
    boolean isEnd = false;
    void insert(String w) {
        Trie n = this;
        for (char c : w.toCharArray()) {
            int i = c - 'a';
            if (n.ch[i] == null) n.ch[i] = new Trie();
            n = n.ch[i];
        }
        n.isEnd = true;
    }
    boolean search(String w) {
        Trie n = find(w);
        return n != null && n.isEnd;
    }
    boolean startsWith(String p) { return find(p) != null; }
    Trie find(String s) {
        Trie n = this;
        for (char c : s.toCharArray()) {
            n = n.ch[c - 'a'];
            if (n == null) return null;
        }
        return n;
    }
}`
  },
  problems: L([
    ['Implement Trie (Prefix Tree)','https://leetcode.com/problems/implement-trie-prefix-tree/','Medium'],
    ['Design Add and Search Words Data Structure','https://leetcode.com/problems/design-add-and-search-words-data-structure/','Medium'],
    ['Word Search II','https://leetcode.com/problems/word-search-ii/','Hard'],
    ['Maximum XOR of Two Numbers in an Array','https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/','Medium']
  ]),
  pitfalls: ['Don\'t forget the isEnd flag — "app" shouldn\'t match "apple" searches.', 'Wildcard search: DFS branching on \'.\' instead of following one child.', 'XOR trie: insert binary representations (31→0 bits); for each number greedily walk the opposite bit.']
},

/* ============ GRAPHS ============ */
{
  topic: 'Graphs', name: 'BFS & DFS Traversal / Connected Components', what: 'BFS explores level by level (queue), DFS dives deep (stack/recursion); run from every unvisited node for components.', when: 'Traversal, component counting, shortest path in unweighted graphs, flood fill, connected/province counting.', tc: 'O(V + E)', sc: 'O(V) visited + queue/stack',
  template: {
    cpp: `vector<vector<int>> adj; vector<int> vis;

void bfs(int src, vector<int>& order) {
    queue<int> q; q.push(src); vis[src] = 1;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        order.push_back(u);
        for (int v : adj[u]) if (!vis[v]) { vis[v] = 1; q.push(v); }
    }
}
void dfs(int u, vector<int>& order) {
    vis[u] = 1;
    order.push_back(u);
    for (int v : adj[u]) if (!vis[v]) dfs(v, order);
}
int components = 0;
for (int i = 0; i < n; i++) if (!vis[i]) { components++; dfs(i, order); }`,
    python: `vis = [False] * n
def bfs(src, order):
    q = deque([src]); vis[src] = True
    while q:
        u = q.popleft()
        order.append(u)
        for v in adj[u]:
            if not vis[v]:
                vis[v] = True
                q.append(v)
def dfs(u, order):
    vis[u] = True
    order.append(u)
    for v in adj[u]:
        if not vis[v]:
            dfs(v, order)
components = sum(1 for i in range(n) if not vis[i] and (dfs(i, []) or True))`,
    java: `void bfs(int src, List<Integer> order) {
    Queue<Integer> q = new ArrayDeque<>(); q.offer(src); vis[src] = true;
    while (!q.isEmpty()) {
        int u = q.poll();
        order.add(u);
        for (int v : adj.get(u)) if (!vis[v]) { vis[v] = true; q.offer(v); }
    }
}
void dfs(int u, List<Integer> order) {
    vis[u] = true;
    order.add(u);
    for (int v : adj.get(u)) if (!vis[v]) dfs(v, order);
}
int components = 0;
for (int i = 0; i < n; i++) if (!vis[i]) { components++; dfs(i, new ArrayList<>()); }`
  },
  problems: L([
    ['Number of Provinces','https://leetcode.com/problems/number-of-provinces/','Medium'],
    ['BFS Traversal (GFG)','https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1','Easy'],
    ['Flood Fill','https://leetcode.com/problems/flood-fill/','Easy'],
    ['Count Connected Components (GFG)','https://www.geeksforgeeks.org/problems/connected-components-in-an-undirected-graph/1','Easy']
  ]),
  pitfalls: ['Mark visited WHEN PUSHING, not when popping — otherwise nodes enter the queue multiple times.', 'DFS recursion can stack-overflow on 10^5+ nodes; use an explicit stack or BFS.', 'Adjacency matrix (n²) vs list (V+E) — pick per input format.']
},
{
  topic: 'Graphs', name: 'Grid BFS/DFS (Islands, Multi-source)', what: 'Treat each cell as a node with 4 (or 8) neighbors; multi-source = push ALL sources into the queue first.', when: 'Number of islands, rotting oranges, 01 matrix, surrounded regions, word search, shortest bridge.', tc: 'O(R·C)', sc: 'O(R·C)',
  template: {
    cpp: `int dr[4] = {1,-1,0,0}, dc[4] = {0,0,1,-1};
int islands(vector<vector<int>>& g) {
    int R = g.size(), C = g[0].size(), cnt = 0;
    for (int r = 0; r < R; r++) for (int c = 0; c < C; c++) {
        if (g[r][c] != 1) continue;
        cnt++;
        queue<pair<int,int>> q; q.push({r, c}); g[r][c] = 0;   // mark on push
        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            for (int d = 0; d < 4; d++) {
                int nx = x + dr[d], ny = y + dc[d];
                if (nx >= 0 && ny >= 0 && nx < R && ny < C && g[nx][ny] == 1) {
                    g[nx][ny] = 0; q.push({nx, ny});
                }
            }
        }
    }
    return cnt;
}
// Multi-source (rotting oranges): push every rotten cell first, BFS in waves = minutes.`,
    python: `DIRS = ((1,0),(-1,0),(0,1),(0,-1))
def islands(g):
    R, C = len(g), len(g[0])
    cnt = 0
    for r in range(R):
        for c in range(C):
            if g[r][c] != 1: continue
            cnt += 1
            q = [(r, c)]; g[r][c] = 0
            while q:
                x, y = q.pop()
                for dx, dy in DIRS:
                    nx, ny = x + dx, y + dy
                    if 0 <= nx < R and 0 <= ny < C and g[nx][ny] == 1:
                        g[nx][ny] = 0
                        q.append((nx, ny))
    return cnt
# Multi-source: push every rotten cell first; wave number = minutes`,
    java: `int[][] D = {{1,0},{-1,0},{0,1},{0,-1}};
int islands(int[][] g) {
    int R = g.length, C = g[0].length, cnt = 0;
    for (int r = 0; r < R; r++) for (int c = 0; c < C; c++) {
        if (g[r][c] != 1) continue;
        cnt++;
        Deque<int[]> q = new ArrayDeque<>(); q.offer(new int[]{r, c}); g[r][c] = 0;
        while (!q.isEmpty()) {
            int[] t = q.poll(); int x = t[0], y = t[1];
            for (int[] d : D) {
                int nx = x + d[0], ny = y + d[1];
                if (nx >= 0 && ny >= 0 && nx < R && ny < C && g[nx][ny] == 1) {
                    g[nx][ny] = 0; q.offer(new int[]{nx, ny});
                }
            }
        }
    }
    return cnt;
}`
  },
  problems: L([
    ['Number of Islands','https://leetcode.com/problems/number-of-islands/','Medium'],
    ['Rotting Oranges','https://leetcode.com/problems/rotting-oranges/','Medium'],
    ['01 Matrix','https://leetcode.com/problems/01-matrix/','Medium'],
    ['Surrounded Regions','https://leetcode.com/problems/surrounded-regions/','Medium']
  ]),
  pitfalls: ['Mark cells visited as you PUSH, not as you pop — or cells get enqueued twice.', 'Multi-source BFS (start all sources together) gives correct distances in one pass.', 'Surrounded regions: reverse-thinking — BFS from border \'O\'s and mark everything else.']
},
{
  topic: 'Graphs', name: 'Topological Sort (Kahn\'s BFS + DFS)', what: 'Linear order of a DAG where every edge points forward; Kahn\'s = repeatedly remove indegree-0 nodes.', when: 'Course schedules, build order, task scheduling, DP-on-DAG processing order, cycle detection in directed graphs.', tc: 'O(V + E)', sc: 'O(V + E)',
  template: {
    cpp: `vector<int> topoKahn(int n, vector<vector<int>>& adj) {
    vector<int> indeg(n, 0);
    for (auto& e : adj) for (int v : e) indeg[v]++;
    queue<int> q; for (int i = 0; i < n; i++) if (!indeg[i]) q.push(i);
    vector<int> order;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        order.push_back(u);
        for (int v : adj[u]) if (--indeg[v] == 0) q.push(v);
    }
    return order;    // if order.size() < n -> cycle exists
}
// DFS version: push node onto a stack AFTER visiting all children, then reverse the stack.`,
    python: `from collections import deque
def topo_kahn(n, adj):
    indeg = [0] * n
    for u in range(n):
        for v in adj[u]:
            indeg[v] += 1
    q = deque(i for i in range(n) if indeg[i] == 0)
    order = []
    while q:
        u = q.popleft()
        order.append(u)
        for v in adj[u]:
            indeg[v] -= 1
            if indeg[v] == 0:
                q.append(v)
    return order   # len(order) < n  ->  cycle`,
    java: `List<Integer> topoKahn(int n, List<List<Integer>> adj) {
    int[] indeg = new int[n];
    for (int u = 0; u < n; u++) for (int v : adj.get(u)) indeg[v]++;
    Queue<Integer> q = new ArrayDeque<>();
    for (int i = 0; i < n; i++) if (indeg[i] == 0) q.offer(i);
    List<Integer> order = new ArrayList<>();
    while (!q.isEmpty()) {
        int u = q.poll();
        order.add(u);
        for (int v : adj.get(u)) if (--indeg[v] == 0) q.offer(v);
    }
    return order;   // order.size() < n -> cycle
}`
  },
  problems: L([
    ['Course Schedule','https://leetcode.com/problems/course-schedule/','Medium'],
    ['Course Schedule II','https://leetcode.com/problems/course-schedule-ii/','Medium'],
    ['Topological Sort (GFG)','https://www.geeksforgeeks.org/problems/topological-sort/1','Medium'],
    ['Alien Dictionary','https://leetcode.com/problems/alien-dictionary/','Hard']
  ]),
  pitfalls: ['order.size() < n ⇒ the graph has a cycle (that IS the course-schedule answer).', 'Edge direction: prerequisites [u,v] usually means v→u or u→v — read carefully.', 'Kahn\'s order is not unique; check whether the problem requires lexicographic smallest (use a min-heap).']
},
{
  topic: 'Graphs', name: 'Cycle Detection (Directed & Undirected)', what: 'Directed: DFS with visit states (in-stack = gray). Undirected: DFS skipping the parent, or DSU edge-by-edge.', when: '"Can finish courses", "detect cycle in directed/undirected graph", redundant connection.', tc: 'O(V + E)', sc: 'O(V)',
  template: {
    cpp: `// directed: vis (ever seen) + pathVis (on current stack)
bool dfs(int u, vector<vector<int>>& adj, vector<int>& vis, vector<int>& pathVis) {
    vis[u] = pathVis[u] = 1;
    for (int v : adj[u]) {
        if (!vis[v] && dfs(v, adj, vis, pathVis)) return true;
        else if (pathVis[v]) return true;      // back edge into current path
    }
    pathVis[u] = 0;                            // leaving this path
    return false;
}
// undirected: dfs(u, parent); if a visited neighbor != parent -> cycle`,
    python: `def dfs(u, adj, vis, path_vis):
    vis[u] = path_vis[u] = True
    for v in adj[u]:
        if not vis[v]:
            if dfs(v, adj, vis, path_vis): return True
        elif path_vis[v]:
            return True          # back edge
    path_vis[u] = False
    return False
# undirected: dfs(u, parent); visited neighbor != parent -> cycle`,
    java: `boolean dfs(int u, List<List<Integer>> adj, int[] vis, int[] pathVis) {
    vis[u] = pathVis[u] = 1;
    for (int v : adj.get(u)) {
        if (vis[v] == 0) { if (dfs(v, adj, vis, pathVis)) return true; }
        else if (pathVis[v] == 1) return true;
    }
    pathVis[u] = 0;
    return false;
}`
  },
  problems: L([
    ['Course Schedule','https://leetcode.com/problems/course-schedule/','Medium'],
    ['Detect Cycle in Undirected Graph (GFG)','https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1','Medium'],
    ['Detect Cycle in Directed Graph (GFG)','https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1','Medium'],
    ['Redundant Connection','https://leetcode.com/problems/redundant-connection/','Medium']
  ]),
  pitfalls: ['Directed needs TWO flags: visited alone gives false positives via cross edges (the diamond graph trap).', 'Undirected parent-skip fails with multi-edges/parallel edges (v→parent twice).', 'Kahn\'s leftover nodes = cycle; DSU detects cycles as you union.']
},
{
  topic: 'Graphs', name: 'Bipartite Check (2-Coloring)', what: 'Try to 2-color the graph with BFS/DFS; odd cycle ⇒ impossible.', when: '"Is graph bipartite", possible partition into two groups, odd-cycle detection.', tc: 'O(V + E)', sc: 'O(V)',
  template: {
    cpp: `// color: 0 uncolored, 1/2 the two colors
bool isBipartite(vector<vector<int>>& g) {
    int n = g.size();
    vector<int> col(n, 0);
    for (int s = 0; s < n; s++) {
        if (col[s]) continue;
        queue<int> q; q.push(s); col[s] = 1;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : g[u]) {
                if (!col[v]) { col[v] = 3 - col[u]; q.push(v); }
                else if (col[v] == col[u]) return false;
            }
        }
    }
    return true;
}`,
    python: `from collections import deque
def is_bipartite(g):
    col = [0] * len(g)
    for s in range(len(g)):
        if col[s]: continue
        q = deque([s]); col[s] = 1
        while q:
            u = q.popleft()
            for v in g[u]:
                if not col[v]:
                    col[v] = 3 - col[u]
                    q.append(v)
                elif col[v] == col[u]:
                    return False
    return True`,
    java: `boolean isBipartite(List<List<Integer>> g) {
    int n = g.size(); int[] col = new int[n];
    for (int s = 0; s < n; s++) {
        if (col[s] != 0) continue;
        Queue<Integer> q = new ArrayDeque<>(); q.offer(s); col[s] = 1;
        while (!q.isEmpty()) {
            int u = q.poll();
            for (int v : g.get(u)) {
                if (col[v] == 0) { col[v] = 3 - col[u]; q.offer(v); }
                else if (col[v] == col[u]) return false;
            }
        }
    }
    return true;
}`
  },
  problems: L([
    ['Is Graph Bipartite?','https://leetcode.com/problems/is-graph-bipartite/','Medium'],
    ['Possible Bipartition','https://leetcode.com/problems/possible-bipartition/','Medium'],
    ['Check Bipartite (GFG)','https://www.geeksforgeeks.org/problems/bipartite-graph/1','Medium']
  ]),
  pitfalls: ['The graph may be disconnected — check every component (loop over all start nodes).', 'col = 3 − col flips 1↔2 in one expression.', 'A graph is bipartite ⟺ it has NO odd cycle.']
},
{
  topic: 'Graphs', name: 'Dijkstra (Priority Queue)', what: 'Greedy SSSP for non-negative weights: always settle the closest unsettled node.', when: 'Single-source shortest path with non-negative weights: network delay, cheapest flights (no k-limit), path with minimum effort, number of ways.', tc: 'O((V+E) log V)', sc: 'O(V + E)',
  template: {
    cpp: `vector<int> dijkstra(int n, int src, vector<vector<pair<int,int>>>& adj) {
    vector<int> dist(n, INT_MAX);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq; // (dist, node)
    dist[src] = 0; pq.push({0, src});
    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;            // stale entry — skip
        for (auto [v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}`,
    python: `import heapq
def dijkstra(n, src, adj):        # adj[u] = [(v, w), ...]
    dist = [float('inf')] * n
    dist[src] = 0
    pq = [(0, src)]
    while pq:
        d, u = heapq.heappop(pq)
        if d > dist[u]: continue   # stale entry
        for v, w in adj[u]:
            if dist[u] + w < dist[v]:
                dist[v] = dist[u] + w
                heapq.heappush(pq, (dist[v], v))
    return dist`,
    java: `int[] dijkstra(int n, int src, List<List<int[]>> adj) {  // adj[u]: {v, w}
    int[] dist = new int[n];
    Arrays.fill(dist, Integer.MAX_VALUE);
    PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] - b[0]);
    dist[src] = 0; pq.offer(new int[]{0, src});
    while (!pq.isEmpty()) {
        int[] t = pq.poll(); int d = t[0], u = t[1];
        if (d > dist[u]) continue;
        for (int[] e : adj.get(u)) {
            int v = e[0], w = e[1];
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.offer(new int[]{dist[v], v});
            }
        }
    }
    return dist;
}`
  },
  problems: L([
    ['Network Delay Time','https://leetcode.com/problems/network-delay-time/','Medium'],
    ['Path With Minimum Effort','https://leetcode.com/problems/path-with-minimum-effort/','Medium'],
    ['Number of Ways to Arrive at Destination','https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/','Medium'],
    ['Cheapest Flights Within K Stops (use Bellman-Ford!)','https://leetcode.com/problems/cheapest-flights-within-k-stops/','Medium']
  ]),
  pitfalls: ['NEGATIVE weights break Dijkstra — use Bellman-Ford.', 'The lazy-deletion check (d > dist[u] → skip) is what keeps it correct with duplicates in the PQ.', 'Cheapest Flights with ≤K stops: greedy Dijkstra fails — use Bellman-Ford limited to K+1 rounds.']
},
{
  topic: 'Graphs', name: 'Bellman-Ford (and Negative Cycles)', what: 'Relax every edge V−1 times; an improvement on the V-th pass means a negative cycle.', when: 'Negative weights, "at most K stops/edges" problems, detecting negative cycles.', tc: 'O(V·E)', sc: 'O(V)',
  template: {
    cpp: `vector<int> dist(n, INT_MAX); dist[src] = 0;
for (int i = 0; i < n - 1; i++) {          // V-1 rounds
    bool changed = false;
    for (auto& [u, v, w] : edges) {
        if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
            dist[v] = dist[u] + w; changed = true;
        }
    }
    if (!changed) break;                    // early exit
}
// one more pass: if any edge can still relax -> negative cycle reachable`,
    python: `dist = [float('inf')] * n
dist[src] = 0
for i in range(n - 1):
    changed = False
    for u, v, w in edges:
        if dist[u] + w < dist[v]:
            dist[v] = dist[u] + w
            changed = True
    if not changed:
        break
# extra pass detecting change -> negative cycle`,
    java: `int[] dist = new int[n];
Arrays.fill(dist, Integer.MAX_VALUE); dist[src] = 0;
for (int i = 0; i < n - 1; i++) {
    boolean changed = false;
    for (int[] e : edges) {
        int u = e[0], v = e[1], w = e[2];
        if (dist[u] != Integer.MAX_VALUE && dist[u] + w < dist[v]) {
            dist[v] = dist[u] + w; changed = true;
        }
    }
    if (!changed) break;
}
// one more pass: still relaxing -> negative cycle`,
  },
  problems: L([
    ['Cheapest Flights Within K Stops','https://leetcode.com/problems/cheapest-flights-within-k-stops/','Medium'],
    ['Bellman-Ford Algorithm (GFG)','https://www.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1','Medium'],
    ['Network Delay Time (alternative)','https://leetcode.com/problems/network-delay-time/','Medium']
  ]),
  pitfalls: ['Guard dist[u] != INF before relaxing (INF + w overflows).', 'For "K stops", run exactly K+1 passes using a COPY of dist (don\'t relax with values updated in the same pass).', 'Early exit when nothing changed in a full round.']
},
{
  topic: 'Graphs', name: 'Floyd-Warshall (All Pairs)', what: 'DP over intermediate vertices k: dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]).', when: 'All-pairs shortest paths (small n ≤ ~500), finding "the city with fewest neighbors at threshold", transitive closure.', tc: 'O(n³)', sc: 'O(n²)',
  template: {
    cpp: `vector<vector<int>> dist(n, vector<int>(n, 1e9));
for (int i = 0; i < n; i++) dist[i][i] = 0;
for (auto& [u, v, w] : edges) dist[u][v] = min(dist[u][v], w);  // keep min for multi-edges
for (int k = 0; k < n; k++)          // intermediate vertex — MUST be the outer loop
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (dist[i][k] + dist[k][j] < dist[i][j])
                dist[i][j] = dist[i][k] + dist[k][j];`,
    python: `dist = [[float('inf')] * n for _ in range(n)]
for i in range(n): dist[i][i] = 0
for u, v, w in edges: dist[u][v] = min(dist[u][v], w)
for k in range(n):
    for i in range(n):
        for j in range(n):
            if dist[i][k] + dist[k][j] < dist[i][j]:
                dist[i][j] = dist[i][k] + dist[k][j]`,
    java: `int[][] dist = new int[n][n];
for (int[] row : dist) Arrays.fill(row, 1_000_000_000);
for (int i = 0; i < n; i++) dist[i][i] = 0;
for (int[] e : edges) dist[e[0]][e[1]] = Math.min(dist[e[0]][e[1]], e[2]);
for (int k = 0; k < n; k++)
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (dist[i][k] + dist[k][j] < dist[i][j])
                dist[i][j] = dist[i][k] + dist[k][j];`
  },
  problems: L([
    ['Find the City With the Smallest Number of Neighbors at a Threshold Distance','https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/','Medium'],
    ['Floyd Warshall (GFG)','https://www.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1','Medium'],
    ['Minimum Cost to Convert String I','https://leetcode.com/problems/minimum-cost-to-convert-string-i/','Medium']
  ]),
  pitfalls: ['k MUST be the outermost loop — that\'s the DP over "allowed intermediate vertices".', 'Multi-edges: take the min when reading edges.', 'Watch overflow: use long or a large-but-safe INF (1e9), never INT_MAX + w.']
},
{
  topic: 'Graphs', name: '0-1 BFS (Deque)', what: 'Weights are 0 or 1: push 0-weight edges to the FRONT of the deque, 1-weight to the BACK.', when: 'Cheap flights with free edges, grid with wall-breaking (cost 1), "minimum removals" path problems.', tc: 'O(V + E)', sc: 'O(V + E)',
  template: {
    cpp: `deque<int> dq; vector<int> dist(n, INT_MAX);
dist[src] = 0; dq.push_front(src);
while (!dq.empty()) {
    int u = dq.front(); dq.pop_front();
    for (auto [v, w] : adj[u]) {
        if (dist[u] + w < dist[v]) {
            dist[v] = dist[u] + w;
            w == 0 ? dq.push_front(v) : dq.push_back(v);
        }
    }
}`,
    python: `from collections import deque
dist = [float('inf')] * n
dist[src] = 0
dq = deque([src])
while dq:
    u = dq.popleft()
    for v, w in adj[u]:
        if dist[u] + w < dist[v]:
            dist[v] = dist[u] + w
            if w == 0: dq.appendleft(v)
            else: dq.append(v)`,
    java: `Deque<Integer> dq = new ArrayDeque<>();
int[] dist = new int[n]; Arrays.fill(dist, Integer.MAX_VALUE);
dist[src] = 0; dq.addFirst(src);
while (!dq.isEmpty()) {
    int u = dq.pollFirst();
    for (int[] e : adj.get(u)) {
        int v = e[0], w = e[1];
        if (dist[u] + w < dist[v]) {
            dist[v] = dist[u] + w;
            if (w == 0) dq.addFirst(v); else dq.addLast(v);
        }
    }
}`
  },
  problems: L([
    ['0-1 BFS practice: Minimum Obstacle Removal to Reach Corner','https://leetcode.com/problems/minimum-obstacle-removal-to-reach-corner/','Hard'],
    ['Minimum Cost to Make at Least One Valid Path in a Grid','https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/','Hard']
  ]),
  pitfalls: ['Only valid for weights 0 and 1 — anything else needs Dijkstra.', 'A node may be re-relaxed; that\'s fine and still O(V+E) amortized.', 'Equivalent alternative: Dijkstra where 0-edges are weight-1 (slower but simpler to reason about).']
},
{
  topic: 'Graphs', name: 'MST — Prim\'s Algorithm', what: 'Grow one tree from any node; always add the cheapest edge leaving the tree (min-heap of frontier edges).', when: 'Minimum spanning tree / minimum wire & pipe cost, connect all points with min cost.', tc: 'O(E log V)', sc: 'O(V + E)',
  template: {
    cpp: `int primMst(int n, vector<vector<pair<int,int>>>& adj) {  // 0..n-1 nodes
    vector<bool> inMst(n, false);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq; // (w, node)
    pq.push({0, 0});
    int total = 0, taken = 0;
    while (!pq.empty() && taken < n) {
        auto [w, u] = pq.top(); pq.pop();
        if (inMst[u]) continue;
        inMst[u] = true; total += w; taken++;
        for (auto [v, wv] : adj[u]) if (!inMst[v]) pq.push({wv, v});
    }
    return taken == n ? total : -1;   // -1 = graph disconnected
}`,
    python: `import heapq
def prim_mst(n, adj):
    in_mst = [False] * n
    pq = [(0, 0)]
    total = taken = 0
    while pq and taken < n:
        w, u = heapq.heappop(pq)
        if in_mst[u]: continue
        in_mst[u] = True; total += w; taken += 1
        for v, wv in adj[u]:
            if not in_mst[v]:
                heapq.heappush(pq, (wv, v))
    return total if taken == n else -1`,
    java: `boolean[] inMst = new boolean[n];
PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] - b[0]);
pq.offer(new int[]{0, 0});
int total = 0, taken = 0;
while (!pq.isEmpty() && taken < n) {
    int[] t = pq.poll(); int w = t[0], u = t[1];
    if (inMst[u]) continue;
    inMst[u] = true; total += w; taken++;
    for (int[] e : adj.get(u)) if (!inMst[e[0]]) pq.offer(new int[]{e[1], e[0]});
}
return taken == n ? total : -1;`
  },
  problems: L([
    ['Min Cost to Connect All Points','https://leetcode.com/problems/min-cost-to-connect-all-points/','Medium'],
    ['Minimum Spanning Tree (GFG)','https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1','Medium']
  ]),
  pitfalls: ['Skip nodes already in the MST when popping (lazy deletion).', 'total edges = n−1; if you take fewer, the graph is disconnected.', 'Prim\'s vs Kruskal: dense graphs → Prim, sparse / edge-list input → Kruskal.']
},
{
  topic: 'Graphs', name: 'MST — Kruskal + DSU', what: 'Sort edges by weight; add each edge if it connects two different components (checked with Union-Find).', when: 'MST from edge list, redundant connection, connecting cities with minimum cost.', tc: 'O(E log E)', sc: 'O(V)',
  template: {
    cpp: `int par[100005], rnk[100005];
int find(int x) { return par[x] == x ? x : par[x] = find(par[x]); }  // path compression
bool unite(int a, int b) {
    a = find(a); b = find(b);
    if (a == b) return false;
    if (rnk[a] < rnk[b]) swap(a, b);
    par[b] = a;
    if (rnk[a] == rnk[b]) rnk[a]++;
    return true;
}
int kruskal(int n, vector<array<int,3>>& edges) {   // {w, u, v}
    sort(edges.begin(), edges.end());
    for (int i = 0; i < n; i++) par[i] = i, rnk[i] = 0;
    int total = 0, used = 0;
    for (auto& [w, u, v] : edges)
        if (unite(u, v)) { total += w; if (++used == n - 1) break; }
    return used == n - 1 ? total : -1;
}`,
    python: `par = list(range(n)); rnk = [0] * n
def find(x):
    while par[x] != x:
        par[x] = par[par[x]]      # path halving
        x = par[x]
    return x
def unite(a, b):
    a, b = find(a), find(b)
    if a == b: return False
    if rnk[a] < rnk[b]: a, b = b, a
    par[b] = a
    if rnk[a] == rnk[b]: rnk[a] += 1
    return True

total = used = 0
for w, u, v in sorted(edges):
    if unite(u, v):
        total += w; used += 1
        if used == n - 1: break`,
    java: `int[] par = new int[n], rnk = new int[n];
for (int i = 0; i < n; i++) par[i] = i;
int find(int x) { return par[x] == x ? x : (par[x] = find(par[x])); }
boolean unite(int a, int b) {
    a = find(a); b = find(b);
    if (a == b) return false;
    if (rnk[a] < rnk[b]) { int t = a; a = b; b = t; }
    par[b] = a;
    if (rnk[a] == rnk[b]) rnk[a]++;
    return true;
}
// sort edges by weight, unite, sum — as in C++`
  },
  problems: L([
    ['Min Cost to Connect All Points','https://leetcode.com/problems/min-cost-to-connect-all-points/','Medium'],
    ['Redundant Connection','https://leetcode.com/problems/redundantconnection/','Medium'],
    ['Connecting Cities With Minimum Cost','https://leetcode.com/problems/connecting-cities-with-minimum-cost/','Medium']
  ]),
  pitfalls: ['find with path compression: par[x] = find(par[x]) — the assignment is the compression.', 'Union by rank/size keeps trees shallow; find stays ~O(α(n)) ≈ O(1).', 'MST needs exactly n−1 edges; count them.']
},
{
  topic: 'Graphs', name: 'DSU / Union-Find (Standalone)', what: 'Track disjoint sets with parent pointers + rank/size; near-O(1) merge and "same set?" queries.', when: '"Same component?" dynamically, accounts merge, evaluating graph formation stage by stage, Kruskal, offline LCA.', tc: 'O(α(n)) ≈ O(1) amortized', sc: 'O(n)',
  template: {
    cpp: `struct DSU {
    vector<int> par, sz;
    DSU(int n) : par(n), sz(n, 1) { iota(par.begin(), par.end(), 0); }
    int find(int x) { return par[x] == x ? x : par[x] = find(par[x]); }
    bool unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return false;
        if (sz[a] < sz[b]) swap(a, b);
        par[b] = a; sz[a] += sz[b];
        return true;
    }
    int size(int x) { return sz[find(x)]; }
};`,
    python: `class DSU:
    def __init__(self, n):
        self.par = list(range(n))
        self.sz = [1] * n
    def find(self, x):
        while self.par[x] != x:
            self.par[x] = self.par[self.par[x]]   # halving
            x = self.par[x]
        return x
    def unite(self, a, b):
        a, b = self.find(a), self.find(b)
        if a == b: return False
        if self.sz[a] < self.sz[b]: a, b = b, a
        self.par[b] = a
        self.sz[a] += self.sz[b]
        return True`,
    java: `class DSU {
    int[] par, sz;
    DSU(int n) { par = new int[n]; sz = new int[n];
        for (int i = 0; i < n; i++) par[i] = i; java.util.Arrays.fill(sz, 1); }
    int find(int x) { return par[x] == x ? x : (par[x] = find(par[x])); }
    boolean unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return false;
        if (sz[a] < sz[b]) { int t = a; a = b; b = t; }
        par[b] = a; sz[a] += sz[b];
        return true;
    }
}`
  },
  problems: L([
    ['Number of Provinces','https://leetcode.com/problems/number-of-provinces/','Medium'],
    ['Accounts Merge','https://leetcode.com/problems/accounts-merge/','Medium'],
    ['Most Stones Removed with Same Row or Column','https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/','Medium'],
    ['Longest Consecutive Sequence (DSU alternative)','https://leetcode.com/problems/longest-consecutive-sequence/','Medium']
  ]),
  pitfalls: ['ALWAYS path-compress (the self-assignment in find) — without it, worst case is O(n) per find.', 'Union by size vs rank — either, just be consistent.', 'For "merge by smallest/largest value" store an extra ext[] mapping root → aggregate.']
},

/* ============ DYNAMIC PROGRAMMING ============ */
{
  topic: 'Dynamic Programming', name: '1D DP (Fibonacci-style / House Robber)', what: 'dp[i] from dp[i-1], dp[i-2]…: memoize (top-down) → tabulate (bottom-up) → space-optimize (keep last 2 vars).', when: 'Climbing stairs, house robber, frog jump, minimum cost climbing, "count/min/max ways" with one index.', tc: 'O(n)', sc: 'O(n) → O(1) optimized',
  template: {
    cpp: `// 1) memoization (top-down)
int f(int i, vector<int>& a, vector<int>& dp) {
    if (i <= 1) return i;
    if (dp[i] != -1) return dp[i];
    return dp[i] = f(i-1, a, dp) + f(i-2, a, dp);
}
// 2) tabulation (bottom-up)
vector<int> dp(n + 1, -1);
dp[0] = 0; dp[1] = 1;
for (int i = 2; i <= n; i++) dp[i] = dp[i-1] + dp[i-2];
// 3) space optimized — two variables
int prev2 = 0, prev = 1;
for (int i = 2; i <= n; i++) { int cur = prev + prev2; prev2 = prev; prev = cur; }`,
    python: `# 1) memoization
from functools import lru_cache
@lru_cache(None)
def f(i):
    if i <= 1: return i
    return f(i-1) + f(i-2)
# 2) tabulation
dp = [0] * (n + 1)
dp[1] = 1
for i in range(2, n + 1):
    dp[i] = dp[i-1] + dp[i-2]
# 3) space optimized
prev2, prev = 0, 1
for _ in range(2, n + 1):
    prev2, prev = prev, prev + prev2`,
    java: `// memoization
int[] dp = new int[n + 1]; Arrays.fill(dp, -1);
int f(int i) {
    if (i <= 1) return i;
    if (dp[i] != -1) return dp[i];
    return dp[i] = f(i-1) + f(i-2);
}
// space optimized
int prev2 = 0, prev = 1;
for (int i = 2; i <= n; i++) { int cur = prev + prev2; prev2 = prev; prev = cur; }`
  },
  problems: L([
    ['Climbing Stairs','https://leetcode.com/problems/climbing-stairs/','Easy'],
    ['House Robber','https://leetcode.com/problems/house-robber/','Medium'],
    ['Frog Jump (GFG)','https://www.geeksforgeeks.org/problems/geek-jump/1','Easy'],
    ['Min Cost Climbing Stairs','https://leetcode.com/problems/min-cost-climbing-stairs/','Easy']
  ]),
  pitfalls: ['Three-step recipe: represent in terms of index → do all choices → take count/min/max.', 'House robber: "no two adjacent" ⇒ dp[i] = max(dp[i-1], dp[i-2] + a[i]).', 'Space-optimize only when dp[i] depends on a bounded window.']
},
{
  topic: 'Dynamic Programming', name: '2D Grid DP', what: 'dp[r][c] built from top/left neighbors; process row by row.', when: 'Unique paths, min path sum, dungeon game, triangle, obstacle grid.', tc: 'O(R·C)', sc: 'O(R·C) → O(C) rolled',
  template: {
    cpp: `// unique paths with obstacles: dp[r][c] = ways to reach (r,c)
vector<vector<int>> dp(R, vector<int>(C, 0));
dp[0][0] = grid[0][0] == 0;
for (int r = 0; r < R; r++) for (int c = 0; c < C; c++) {
    if (grid[r][c] == 1) { dp[r][c] = 0; continue; }   // obstacle
    if (r > 0) dp[r][c] += dp[r-1][c];
    if (c > 0) dp[r][c] += dp[r][c-1];
}
// min path sum: dp[r][c] = grid[r][c] + min(dp[r-1][c], dp[r][c-1])`,
    python: `dp = [[0] * C for _ in range(R)]
dp[0][0] = 1 if grid[0][0] == 0 else 0
for r in range(R):
    for c in range(C):
        if grid[r][c] == 1:
            dp[r][c] = 0
            continue
        if r > 0: dp[r][c] += dp[r-1][c]
        if c > 0: dp[r][c] += dp[r][c-1]`,
    java: `int[][] dp = new int[R][C];
dp[0][0] = grid[0][0] == 0 ? 1 : 0;
for (int r = 0; r < R; r++) for (int c = 0; c < C; c++) {
    if (grid[r][c] == 1) { dp[r][c] = 0; continue; }
    if (r > 0) dp[r][c] += dp[r-1][c];
    if (c > 0) dp[r][c] += dp[r][c-1];
}`
  },
  problems: L([
    ['Unique Paths','https://leetcode.com/problems/unique-paths/','Medium'],
    ['Minimum Path Sum','https://leetcode.com/problems/minimum-path-sum/','Medium'],
    ['Unique Paths II','https://leetcode.com/problems/unique-paths-ii/','Medium'],
    ['Triangle','https://leetcode.com/problems/triangle/','Medium']
  ]),
  pitfalls: ['First row/column have only one way to be reached — initialize separately.', 'Roll to 1D when only the previous row matters.', 'Dungeon game needs BACKWARD DP (from bottom-right) because of negative values.']
},
{
  topic: 'Dynamic Programming', name: '0/1 Knapsack (Subset Sum family)', what: 'Each item used once: dp[cap] = max(dp[cap], dp[cap-w] + val); iterate capacity DESCENDING to prevent reuse.', when: 'Partition equal subset, target sum, last stone II, "pick items with weight/value ≤ capacity".', tc: 'O(n·W)', sc: 'O(W)',
  template: {
    cpp: `// classic 0/1 knapsack
vector<int> dp(W + 1, 0);
for (int i = 0; i < n; i++)
    for (int cap = W; cap >= wt[i]; cap--)          // DESCENDING: item used once
        dp[cap] = max(dp[cap], dp[cap - wt[i]] + val[i]);
// subset sum to target:
// dp = bitset<target+1>; dp[0] = 1; for w in a: dp |= dp << w;
// partition equal subset: sum/2 as target`,
    python: `dp = [0] * (W + 1)
for i in range(n):
    for cap in range(W, wt[i] - 1, -1):    # DESCENDING: item used once
        dp[cap] = max(dp[cap], dp[cap - wt[i]] + val[i])
# subset sum:
# dp = [False] * (target + 1); dp[0] = True
# for w in a:
#     for s in range(target, w - 1, -1): dp[s] = dp[s] or dp[s - w]`,
    java: `int[] dp = new int[W + 1];
for (int i = 0; i < n; i++)
    for (int cap = W; cap >= wt[i]; cap--)
        dp[cap] = Math.max(dp[cap], dp[cap - wt[i]] + val[i]);`
  },
  problems: L([
    ['Partition Equal Subset Sum','https://leetcode.com/problems/partition-equal-subset-sum/','Medium'],
    ['Target Sum','https://leetcode.com/problems/target-sum/','Medium'],
    ['Last Stone Weight II','https://leetcode.com/problems/last-stone-weight-ii/','Medium'],
    ['0-1 Knapsack (GFG)','https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1','Medium']
  ]),
  pitfalls: ['Capacity loop MUST be descending for 0/1 (ascending = unbounded knapsack).', 'Partition odd sum → false immediately.', 'dp over "achievable sums" as booleans is often the cleaner framing.']
},
{
  topic: 'Dynamic Programming', name: 'Unbounded Knapsack (Coin Change)', what: 'Items reusable: iterate capacity ASCENDING; dp[amt] = min coins / count of ways using any coin repeatedly.', when: 'Coin change (min coins), coin change II (count ways), rod cutting, integer break.', tc: 'O(n·amount)', sc: 'O(amount)',
  template: {
    cpp: `// min coins
vector<int> dp(amount + 1, amount + 1); dp[0] = 0;
for (int amt = 1; amt <= amount; amt++)
    for (int c : coins)
        if (c <= amt) dp[amt] = min(dp[amt], dp[amt - c] + 1);
return dp[amount] > amount ? -1 : dp[amount];

// count ways (order-independent): loop coins OUTSIDE, amount inside
vector<long long> ways(amount + 1, 0); ways[0] = 1;
for (int c : coins)
    for (int amt = c; amt <= amount; amt++)
        ways[amt] += ways[amt - c];`,
    python: `dp = [float('inf')] * (amount + 1)
dp[0] = 0
for amt in range(1, amount + 1):
    for c in coins:
        if c <= amt:
            dp[amt] = min(dp[amt], dp[amt - c] + 1)
return dp[amount] if dp[amount] != float('inf') else -1

# count ways: coins outside, amount inside
ways = [0] * (amount + 1); ways[0] = 1
for c in coins:
    for amt in range(c, amount + 1):
        ways[amt] += ways[amt - c]`,
    java: `int[] dp = new int[amount + 1];
Arrays.fill(dp, amount + 1); dp[0] = 0;
for (int amt = 1; amt <= amount; amt++)
    for (int c : coins)
        if (c <= amt) dp[amt] = Math.min(dp[amt], dp[amt - c] + 1);
return dp[amount] > amount ? -1 : dp[amount];`
  },
  problems: L([
    ['Coin Change','https://leetcode.com/problems/coin-change/','Medium'],
    ['Coin Change II (ways)','https://leetcode.com/problems/coin-change-ii/','Medium'],
    ['Rod Cutting (GFG)','https://www.geeksforgeeks.org/problems/rod-cutting0840/1','Medium'],
    ['Perfect Squares','https://leetcode.com/problems/perfect-squares/','Medium']
  ]),
  pitfalls: ['Min-coins: coins inside the amount loop. Count-ways: coins OUTSIDE (swapping loops counts permutations instead of combinations).', 'Initialize min-coins dp with INF and dp[0] = 0.', 'Impossible amount = dp stays INF → return -1.']
},
{
  topic: 'Dynamic Programming', name: 'Longest Increasing Subsequence', what: 'O(n²) DP, or O(n log n): tails[] keeps the smallest tail of each length — binary search its position.', when: 'LIS, maximum height stack, envelopes nesting, longest bitonic / divisible subsets.', tc: 'O(n log n)', sc: 'O(n)',
  template: {
    cpp: `// O(n log n) — tails[i] = smallest tail of an increasing subsequence of length i+1
vector<int> tails;
for (int x : a) {
    auto it = lower_bound(tails.begin(), tails.end(), x);
    if (it == tails.end()) tails.push_back(x);   // extends the longest
    else *it = x;                                // improve an existing tail
}
// tails.size() = LIS length (tails itself is NOT a valid subsequence)
// for strictly increasing use lower_bound; for non-decreasing use upper_bound`,
    python: `import bisect
tails = []
for x in a:
    i = bisect.bisect_left(tails, x)
    if i == len(tails):
        tails.append(x)
    else:
        tails[i] = x
# len(tails) = LIS length
# O(n^2) DP: dp[i] = 1 + max(dp[j] for j<i if a[j] < a[i], default 0)`,
    java: `List<Integer> tails = new ArrayList<>();
for (int x : a) {
    int i = Collections.binarySearch(tails, x);
    if (i < 0) i = -(i + 1);              // insertion point == lower bound
    if (i == tails.size()) tails.add(x);
    else tails.set(i, x);
}
// tails.size() = LIS length`
  },
  problems: L([
    ['Longest Increasing Subsequence','https://leetcode.com/problems/longest-increasing-subsequence/','Medium'],
    ['Russian Doll Envelopes','https://leetcode.com/problems/russian-doll-envelopes/','Hard'],
    ['Maximum Height by Stacking Cuboids','https://leetcode.com/problems/maximum-height-by-stacking-cuboids/','Hard'],
    ['Number of Longest Increasing Subsequence','https://leetcode.com/problems/number-of-longest-increasing-subsequence/','Medium']
  ]),
  pitfalls: ['tails is not the actual LIS — only its length is correct.', 'lower_bound → strictly increasing; upper_bound → non-decreasing.', 'Envelopes: sort width asc, height DESC for equal widths (kills false chains).']
},
{
  topic: 'Dynamic Programming', name: 'LCS / Two-String DP', what: 'dp[i][j] = answer for prefixes a[:i], b[:j]; match → diagonal + 1, else max(up, left).', when: 'LCS, shortest common supersequence, min insertions/deletions, min ASCII delete,_uncmmon subsequences.', tc: 'O(n·m)', sc: 'O(n·m) → O(m) rolled',
  template: {
    cpp: `vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
        if (a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
        else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    }
// LCS length = dp[n][m]
// deletions = n + m - 2*LCS; SCS length = n + m - LCS`,
    python: `dp = [[0] * (m + 1) for _ in range(n + 1)]
for i in range(1, n + 1):
    for j in range(1, m + 1):
        if a[i-1] == b[j-1]:
            dp[i][j] = dp[i-1][j-1] + 1
        else:
            dp[i][j] = max(dp[i-1][j], dp[i][j-1])
# dp[n][m] = LCS length`,
    java: `int[][] dp = new int[n + 1][m + 1];
for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
        if (a.charAt(i-1) == b.charAt(j-1)) dp[i][j] = dp[i-1][j-1] + 1;
        else dp[i][j] = Math.max(dp[i-1][j], dp[i][j-1]);
    }`
  },
  problems: L([
    ['Longest Common Subsequence','https://leetcode.com/problems/longest-common-subsequence/','Medium'],
    ['Shortest Common Supersequence','https://leetcode.com/problems/shortest-common-supersequence/','Hard'],
    ['Minimum ASCII Delete Sum for Two Strings','https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/','Medium'],
    ['Longest Palindromic Subsequence','https://leetcode.com/problems/longest-palindromic-subsequence/','Medium']
  ]),
  pitfalls: ['Index carefully: dp[i][j] uses a[i-1], b[j-1] because of the +1 padding.', 'Longest palindromic subsequence = LCS(s, reverse(s)).', 'Printing the SCS: walk the table backwards, take both chars on mismatch.']
},
{
  topic: 'Dynamic Programming', name: 'Edit Distance', what: 'dp[i][j] = min ops to convert a[:i] → b[:j]: insert / delete / replace from three neighbors.', when: 'Edit distance, one-edit-away, "convert word1 to word2 with min operations".', tc: 'O(n·m)', sc: 'O(n·m) → O(m)',
  template: {
    cpp: `vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
for (int i = 0; i <= n; i++) dp[i][0] = i;   // delete all
for (int j = 0; j <= m; j++) dp[0][j] = j;   // insert all
for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
        if (a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1];
        else dp[i][j] = 1 + min({ dp[i-1][j-1],   // replace
                                  dp[i-1][j],     // delete
                                  dp[i][j-1] });  // insert
    }`,
    python: `dp = [[0] * (m + 1) for _ in range(n + 1)]
for i in range(n + 1): dp[i][0] = i
for j in range(m + 1): dp[0][j] = j
for i in range(1, n + 1):
    for j in range(1, m + 1):
        if a[i-1] == b[j-1]:
            dp[i][j] = dp[i-1][j-1]
        else:
            dp[i][j] = 1 + min(dp[i-1][j-1], dp[i-1][j], dp[i][j-1])`,
    java: `int[][] dp = new int[n + 1][m + 1];
for (int i = 0; i <= n; i++) dp[i][0] = i;
for (int j = 0; j <= m; j++) dp[0][j] = j;
for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
        dp[i][j] = (a.charAt(i-1) == b.charAt(j-1))
            ? dp[i-1][j-1]
            : 1 + Math.min(dp[i-1][j-1], Math.min(dp[i-1][j], dp[i][j-1]));`
  },
  problems: L([
    ['Edit Distance','https://leetcode.com/problems/edit-distance/','Medium'],
    ['Delete Operation for Two Strings','https://leetcode.com/problems/delete-operation-for-two-strings/','Medium'],
    ['One Edit Distance','https://leetcode.com/problems/one-edit-distance/','Medium']
  ]),
  pitfalls: ['Base row/column = index (i or j ops), not 0.', 'Match ⇒ free diagonal move; don\'t forget the else.', 'Space-optimized version keeps only two rows.']
},
{
  topic: 'Dynamic Programming', name: 'MCM / Interval DP', what: 'dp[i][j] = best answer for interval [i..j]; try every split k: dp[i][j] = min/max(dp[i][k] + dp[k+1][j] + cost(i,j)).', when: 'Matrix chain multiplication, burst balloons, palindrome partitioning II, min cost to cut a stick.', tc: 'O(n³)', sc: 'O(n²)',
  template: {
    cpp: `// min cost to cut / burst balloons: pad boundaries, split on every k
// a = [0, ...cuts..., L] sorted
vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
for (int len = 2; len <= n + 1; len++)            // interval length
    for (int i = 0; i + len <= n + 1; i++) {
        int j = i + len;
        dp[i][j] = INT_MAX;
        for (int k = i + 1; k < j; k++)           // try each split point
            dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + a[j] - a[i]);
    }
// answer = dp[0][n+1]`,
    python: `dp = [[0] * (n + 2) for _ in range(n + 2)]
for length in range(2, n + 2):
    for i in range(0, n + 2 - length):
        j = i + length
        dp[i][j] = float('inf')
        for k in range(i + 1, j):
            dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + a[j] - a[i])`,
    java: `int[][] dp = new int[n + 2][n + 2];
for (int len = 2; len <= n + 1; len++)
    for (int i = 0; i + len <= n + 1; i++) {
        int j = i + len;
        dp[i][j] = Integer.MAX_VALUE;
        for (int k = i + 1; k < j; k++)
            dp[i][j] = Math.min(dp[i][j], dp[i][k] + dp[k][j] + a[j] - a[i]);
    }`
  },
  problems: L([
    ['Burst Balloons','https://leetcode.com/problems/burst-balloons/','Hard'],
    ['Matrix Chain Multiplication (GFG)','https://www.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1','Hard'],
    ['Palindrome Partitioning II','https://leetcode.com/problems/palindrome-partitioning-ii/','Hard'],
    ['Minimum Cost to Cut a Stick','https://leetcode.com/problems/minimum-cost-to-cut-a-stick/','Hard']
  ]),
  pitfalls: ['Iterate interval LENGTHS, not naive (i,j) order — dp[i][j] needs shorter intervals ready.', 'Burst balloons: think "last balloon burst in (i,j)" with padded boundaries 1.', 'Palindrome partition: precompute isPal with its own DP first.']
},
{
  topic: 'Dynamic Programming', name: 'DP on Trees', what: 'DFS returns per-node DP values; parent combines children\'s states (often 2 states: take/skip node).', when: 'Diameter, house robber III, max path sum, tree matching, min vertex cover.', tc: 'O(n)', sc: 'O(h)',
  template: {
    cpp: `// classic: {take, skip} per node — house robber III pattern
pair<int,int> dfs(Node* r) {              // {rob, notRob}
    if (!r) return {0, 0};
    auto [lt, ls] = dfs(r->left);
    auto [rt, rs] = dfs(r->right);
    int take = r->val + ls + rs;          // children must be skipped
    int skip = max(lt, ls) + max(rt, rs); // free choice for children
    return {take, skip};
}
// diameter: depth DFS updating a global best = max(best, ldepth + rdepth)`,
    python: `def dfs(r):
    if not r: return (0, 0)          # (take, skip)
    lt, ls = dfs(r.left)
    rt, rs = dfs(r.right)
    take = r.val + ls + rs
    skip = max(lt, ls) + max(rt, rs)
    return (take, skip)`,
    java: `int[] dfs(Node r) {                  // {take, skip}
    if (r == null) return new int[]{0, 0};
    int[] L = dfs(r.left), R = dfs(r.right);
    int take = r.val + L[1] + R[1];
    int skip = Math.max(L[0], L[1]) + Math.max(R[0], R[1]);
    return new int[]{take, skip};
}`
  },
  problems: L([
    ['House Robber III','https://leetcode.com/problems/house-robber-iii/','Medium'],
    ['Diameter of Binary Tree','https://leetcode.com/problems/diameter-of-binary-tree/','Easy'],
    ['Binary Tree Maximum Path Sum','https://leetcode.com/problems/binary-tree-maximum-path-sum/','Hard']
  ]),
  pitfalls: ['Return multiple states via pair/struct — single value is usually not enough.', 'Diameter: update the global answer inside DFS, return only the depth.', 'Careful: "take node" forces skipping children, but "skip" still allows taking them.']
},
{
  topic: 'Dynamic Programming', name: 'Bitmask DP', what: 'dp[mask] = best for the set of items/visited nodes encoded in mask; transitions flip one bit.', when: 'TSP (n ≤ ~20), assignment problems, "min cost to visit all", partition into k equal subsets.', tc: 'O(2^n · n) typical', sc: 'O(2^n)',
  template: {
    cpp: `// TSP: dp[mask][i] = min cost path visiting set 'mask', ending at i
vector<vector<int>> dp(1 << n, vector<int>(n, INT_MAX));
dp[1][0] = 0;                                  // start at 0
for (int mask = 1; mask < (1 << n); mask++)
    for (int i = 0; i < n; i++) {
        if (dp[mask][i] == INT_MAX || !(mask & (1 << i))) continue;
        for (int j = 0; j < n; j++) {
            if (mask & (1 << j)) continue;
            int nm = mask | (1 << j);
            dp[nm][j] = min(dp[nm][j], dp[mask][i] + dist[i][j]);
        }
    }
// answer = *min_element(dp[(1<<n) - 1].begin(), dp[(1<<n) - 1].end());`,
    python: `dp = [[float('inf')] * n for _ in range(1 << n)]
dp[1][0] = 0
for mask in range(1, 1 << n):
    for i in range(n):
        if dp[mask][i] == float('inf') or not (mask >> i) & 1:
            continue
        for j in range(n):
            if (mask >> j) & 1: continue
            nm = mask | (1 << j)
            dp[nm][j] = min(dp[nm][j], dp[mask][i] + dist[i][j])`,
    java: `int[][] dp = new int[1 << n][n];
for (int[] row : dp) Arrays.fill(row, Integer.MAX_VALUE);
dp[1][0] = 0;
for (int mask = 1; mask < (1 << n); mask++)
    for (int i = 0; i < n; i++) {
        if (dp[mask][i] == Integer.MAX_VALUE || (mask & (1 << i)) == 0) continue;
        for (int j = 0; j < n; j++) {
            if ((mask & (1 << j)) != 0) continue;
            int nm = mask | (1 << j);
            dp[nm][j] = Math.min(dp[nm][j], dp[mask][i] + dist[i][j]);
        }
    }`
  },
  problems: L([
    ['Find the Shortest Superstring','https://leetcode.com/problems/shortest-superstring/','Hard'],
    ['Partition to K Equal Sum Subsets','https://leetcode.com/problems/partition-to-k-equal-sum-subsets/','Medium'],
    ['Cost to Connect Two Groups of Points','https://leetcode.com/problems/minimum-cost-to-connect-two-groups-of-points/','Hard']
  ]),
  pitfalls: ['Only feasible for n ≤ ~20 (2^20 states × n transitions).', 'Iterate masks in increasing order — bigger masks are built from smaller ones.', 'Bit tricks: test bit (mask>>i)&1, set mask|1<<i, clear mask&~(1<<i).']
},
{
  topic: 'Dynamic Programming', name: 'Digit DP', what: 'Count numbers ≤ N with a property: process digits left→right with state (position, constraint tight?, extra state).', when: '"Count numbers with X in [L, R]", sum of digits, repeated digits, numbers without leading zeros.', tc: 'O(len × states × 10)', sc: 'O(len × states)',
  template: {
    cpp: `string s;                     // upper bound N as a string
long long memo[20][2][state_size];
long long go(int pos, bool tight, int state) {
    if (pos == (int)s.size()) return valid(state);    // base: 1 if final state valid
    if (!tight && memo[pos][0][state] != -1) return memo[pos][0][state];
    int hi = tight ? s[pos] - '0' : 9;
    long long res = 0;
    for (int d = 0; d <= hi; d++)
        res += go(pos + 1, tight && d == hi, newState(state, d));
    if (!tight) memo[pos][0][state] = res;
    return res;
}
// answer(L, R) = count(R) - count(L - 1)`,
    python: `from functools import lru_cache
def count(x):
    s = str(x)
    @lru_cache(None)
    def go(pos, tight, state):
        if pos == len(s):
            return 1 if valid(state) else 0
        hi = int(s[pos]) if tight else 9
        return sum(go(pos + 1, tight and d == hi, new_state(state, d))
                   for d in range(hi + 1))
    return go(0, True, init_state)
# answer = count(R) - count(L - 1)`,
    java: `String s; long[][][] memo;
long go(int pos, boolean tight, int state) {
    if (pos == s.length()) return valid(state) ? 1 : 0;
    if (!tight && memo[pos][0][state] != -1) return memo[pos][0][state];
    int hi = tight ? s.charAt(pos) - '0' : 9;
    long res = 0;
    for (int d = 0; d <= hi; d++)
        res += go(pos + 1, tight && d == hi, newState(state, d));
    if (!tight) memo[pos][0][state] = res;
    return res;
}
// answer(L, R) = count(R) - count(L - 1)`
  },
  problems: L([
    ['Count Numbers with Unique Digits','https://leetcode.com/problems/count-numbers-with-unique-digits/','Medium'],
    ['Numbers At Most N Given Digit Set','https://leetcode.com/problems/numbers-at-most-n-given-digit-set/','Hard'],
    ['Number of Digit One','https://leetcode.com/problems/number-of-digit-one/','Hard']
  ]),
  pitfalls: ['The tight flag: once you place a digit below the bound, tight becomes false forever.', 'Answer for a range = f(R) − f(L−1) (careful with L=0).', 'Leading zeros usually need an extra "started" state.']
},

/* ============ GREEDY ============ */
{
  topic: 'Greedy', name: 'Sort + Single Pass (Activity Selection family)', what: 'Sort by the "end" (or key) that frees you up earliest, then greedily take compatible items.', when: 'Non-overlapping intervals, assign cookies, min arrows to burst balloons, merge triplets.', tc: 'O(n log n)', sc: 'O(1)',
  template: {
    cpp: `// max non-overlapping intervals: sort by END, take if start >= lastEnd
sort(iv.begin(), iv.end(), [](auto& a, auto& b){ return a[1] < b[1]; });
int taken = 0, lastEnd = INT_MIN;
for (auto& i : iv)
    if (i[0] >= lastEnd) { taken++; lastEnd = i[1]; }
// deletions needed = n - taken`,
    python: `iv.sort(key=lambda x: x[1])    # by end
taken, last_end = 0, float('-inf')
for s, e in iv:
    if s >= last_end:
        taken += 1
        last_end = e
# removals = n - taken`,
    java: `Arrays.sort(iv, (a, b) -> Integer.compare(a[1], b[1]));
int taken = 0, lastEnd = Integer.MIN_VALUE;
for (int[] i : iv)
    if (i[0] >= lastEnd) { taken++; lastEnd = i[1]; }`
  },
  problems: L([
    ['Non-overlapping Intervals','https://leetcode.com/problems/non-overlapping-intervals/','Medium'],
    ['Assign Cookies','https://leetcode.com/problems/assign-cookies/','Easy'],
    ['Minimum Number of Arrows to Burst Balloons','https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/','Medium'],
    ['Merge Triplets to Form Target Triplet','https://leetcode.com/problems/merge-triplets-to-form-target-triplet/','Medium']
  ]),
  pitfalls: ['Sort by END for "max activities" (earliest end leaves room); sorting by start only helps counting overlaps.', 'Proof sketch: exchange argument — greedy first pick can be swapped with any valid pick.', 'Greedy problems have no clear DP framing; if local choice looks wrong, try DP instead.']
},
{
  topic: 'Greedy', name: 'Reachability Greedy (Jump Game / Gas Station)', what: 'Track the furthest reachable index (or fuel balance) in one pass — restart when infeasible.', when: 'Jump game I/II, gas station, video stitching, partition labels.', tc: 'O(n)', sc: 'O(1)',
  template: {
    cpp: `// jump game I — can reach the end?
int reach = 0;
for (int i = 0; i < n; i++) {
    if (i > reach) return false;      // stuck before i
    reach = max(reach, i + a[i]);
}
return true;

// gas station — start index where balance never dips
long long bal = 0, total = 0; int start = 0;
for (int i = 0; i < n; i++) {
    bal += gas[i] - cost[i]; total += gas[i] - cost[i];
    if (bal < 0) { start = i + 1; bal = 0; }   // restart after i
}
return total >= 0 ? start : -1;`,
    python: `reach = 0
for i in range(len(a)):
    if i > reach: return False
    reach = max(reach, i + a[i])
return True

# gas station
bal = total = 0; start = 0
for i in range(len(gas)):
    d = gas[i] - cost[i]
    bal += d; total += d
    if bal < 0: start, bal = i + 1, 0
return start if total >= 0 else -1`,
    java: `int reach = 0;
for (int i = 0; i < n; i++) {
    if (i > reach) return false;
    reach = Math.max(reach, i + a[i]);
}
return true;

long bal = 0, total = 0; int start = 0;
for (int i = 0; i < n; i++) {
    long d = gas[i] - cost[i];
    bal += d; total += d;
    if (bal < 0) { start = i + 1; bal = 0; }
}
return total >= 0 ? start : -1;`
  },
  problems: L([
    ['Jump Game','https://leetcode.com/problems/jump-game/','Medium'],
    ['Jump Game II','https://leetcode.com/problems/jump-game-ii/','Medium'],
    ['Gas Station','https://leetcode.com/problems/gas-station/','Medium'],
    ['Partition Labels','https://leetcode.com/problems/partition-labels/','Medium']
  ]),
  pitfalls: ['If i > reach you\'re stuck — that\'s the whole proof.', 'Gas station: if total < 0 no answer exists; else the position after the last dip is the unique start.', 'Jump Game II: BFS-layer intuition — current level = [l, r], next level = farthest reach.']
},

/* ============ BIT MANIPULATION ============ */
{
  topic: 'Bit Manipulation', name: 'Bit Basics (Get / Set / Clear / Toggle)', what: 'Masks: check (n>>k)&1, set n|1<<k, clear n&~(1<<k), toggle n^1<<k; n&(n-1) drops the lowest set bit.', when: 'Kth bit queries, power-of-two check, counting bits, flags/state compression.', tc: 'O(1) per op / O(log n) to scan bits', sc: 'O(1)',
  template: {
    cpp: `bool getBit   (int n, int k) { return (n >> k) & 1; }
int  setBit   (int n, int k) { return n | (1 << k); }
int  clearBit (int n, int k) { return n & ~(1 << k); }
int  toggleBit(int n, int k) { return n ^ (1 << k); }
bool isPowerOfTwo(int n) { return n > 0 && (n & (n - 1)) == 0; }  // one set bit
int  countBits(int n) { int c = 0; while (n) { n &= n - 1; c++; } return c; }  // Kernighan
// n & -n isolates the lowest set bit; n / 2 == n >> 1; n * 2 == n << 1`,
    python: `def get_bit(n, k):    return (n >> k) & 1 == 1
def set_bit(n, k):    return n | (1 << k)
def clear_bit(n, k):  return n & ~(1 << k)
def toggle_bit(n, k): return n ^ (1 << k)
def is_power_of_two(n): return n > 0 and (n & (n - 1)) == 0
def count_bits(n):
    c = 0
    while n:
        n &= n - 1
        c += 1
    return c
# bin(n).count('1') also works`,
    java: `boolean getBit(int n, int k)    { return (n >> k & 1) == 1; }
int setBit(int n, int k)        { return n | (1 << k); }
int clearBit(int n, int k)      { return n & ~(1 << k); }
int toggleBit(int n, int k)     { return n ^ (1 << k); }
boolean isPowerOfTwo(int n)     { return n > 0 && (n & (n - 1)) == 0; }
int countBits(int n)            { return Integer.bitCount(n); }`
  },
  problems: L([
    ['Number of 1 Bits','https://leetcode.com/problems/number-of-1-bits/','Easy'],
    ['Power of Two','https://leetcode.com/problems/power-of-two/','Easy'],
    ['Counting Bits','https://leetcode.com/problems/counting-bits/','Easy'],
    ['Reverse Bits','https://leetcode.com/problems/reverse-bits/','Easy']
  ]),
  pitfalls: ['Negative numbers: right shift is arithmetic in C++/Java (sign-extends); use unsigned for logical shifts.', '1 << k overflows when k ≥ 31 — use 1L << k for longs.', 'n & (n-1) == 0 also true for n = 0 — guard n > 0.']
},
{
  topic: 'Bit Manipulation', name: 'XOR Tricks', what: 'x^x=0, x^0=x — XOR all elements to cancel pairs and isolate the odd one out.', when: 'Single number I/II/III, missing number, two missing numbers, swap without temp (never in real code).', tc: 'O(n)', sc: 'O(1)',
  template: {
    cpp: `int x = 0;                       // single number: pairs cancel, odd one remains
for (int v : a) x ^= v;
// missing number: xor 0..n with all elements
int miss = 0;
for (int i = 0; i < n; i++) miss ^= i ^ a[i];
miss ^= n;
// two singles: x = a^b, any set bit of x splits the array into two groups
int xr = 0; for (int v : a) xr ^= v;
int bit = xr & -xr;              // lowest set bit where a and b differ
int g1 = 0, g2 = 0;
for (int v : a) (v & bit ? g1 : g2) ^= v;   // g1, g2 = the two singles`,
    python: `x = 0
for v in a: x ^= v               # single number
miss = 0
for i, v in enumerate(a): miss ^= i ^ v
miss ^= len(a)                   # missing number
# two singles:
xr = 0
for v in a: xr ^= v
bit = xr & -xr
g1 = g2 = 0
for v in a:
    if v & bit: g1 ^= v
    else: g2 ^= v`,
    java: `int x = 0;
for (int v : a) x ^= v;                       // single number
int miss = 0;
for (int i = 0; i < n; i++) miss ^= i ^ a[i];
miss ^= n;                                    // missing number
int xr = 0; for (int v : a) xr ^= v;
int bit = xr & (-xr);
int g1 = 0, g2 = 0;
for (int v : a) { if ((v & bit) != 0) g1 ^= v; else g2 ^= v; }`
  },
  problems: L([
    ['Single Number','https://leetcode.com/problems/single-number/','Easy'],
    ['Missing Number','https://leetcode.com/problems/missing-number/','Easy'],
    ['Single Number II (every element thrice)','https://leetcode.com/problems/single-number-ii/','Medium'],
    ['Single Number III (two singles)','https://leetcode.com/problems/single-number-iii/','Medium']
  ]),
  pitfalls: ['Single Number II (thrice + one): count bits per position % 3, or use ones/twos two-variable trick.', 'XOR is commutative — order doesn\'t matter, start with 0.', 'n & -n: for negative numbers in Java/C++ this works via two\'s complement, but Python ints are unbounded — still fine for positive masks.']
},

/* ============ MATH & NUMBER THEORY ============ */
{
  topic: 'Math & Number Theory', name: 'GCD / LCM (Euclid)', what: 'gcd(a, b) = gcd(b, a mod b); lcm = a / gcd × b. Runs in O(log min).', when: 'Fraction simplification, common divisors, "greatest common divisor of strings", interval overlap.', tc: 'O(log min(a, b))', sc: 'O(1)',
  template: {
    cpp: `long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }  // divide FIRST (overflow)`,
    python: `import math
g = math.gcd(a, b)                     # built-in
l = a // g * b                          # lcm via gcd`,
    java: `long gcd(long a, long b) { return b == 0 ? a : gcd(b, a % b); }
long lcm(long a, long b) { return a / gcd(a, b) * b; }`
  },
  problems: L([
    ['Greatest Common Divisor of Strings','https://leetcode.com/problems/greatest-common-divisor-of-strings/','Easy'],
    ['Find Greatest Common Divisor of Array','https://leetcode.com/problems/find-greatest-common-divisor-of-array/','Easy']
  ]),
  pitfalls: ['lcm: divide before multiplying (a / g * b) or you overflow.', 'gcd(a, 0) = a — the recursion base.', 'gcd of strings: gcd(s1, s2) exists iff s1+s2 == s2+s1, length = gcd(len1, len2).']
},
{
  topic: 'Math & Number Theory', name: 'Sieve of Eratosthenes', what: 'Boolean array; for each prime p, mark multiples starting at p² as composite.', when: 'Count primes ≤ n, smallest prime factor precomputation, prime queries in ranges.', tc: 'O(n log log n)', sc: 'O(n)',
  template: {
    cpp: `vector<bool> isPrime(n + 1, true);
isPrime[0] = isPrime[1] = false;
for (int p = 2; (long long)p * p <= n; p++)
    if (isPrime[p])
        for (long long m = (long long)p * p; m <= n; m += p)  // start at p*p
            isPrime[m] = false;
// spf (smallest prime factor) variant: spf[m] = p when first marked`,
    python: `n = 10**6
is_prime = [True] * (n + 1)
is_prime[0] = is_prime[1] = False
for p in range(2, int(n ** 0.5) + 1):
    if is_prime[p]:
        for m in range(p * p, n + 1, p):
            is_prime[m] = False`,
    java: `boolean[] isPrime = new boolean[n + 1];
Arrays.fill(isPrime, true);
isPrime[0] = isPrime[1] = false;
for (int p = 2; (long) p * p <= n; p++)
    if (isPrime[p])
        for (long m = (long) p * p; m <= n; m += p)
            isPrime[(int) m] = false;`
  },
  problems: L([
    ['Count Primes','https://leetcode.com/problems/count-primes/','Medium'],
    ['Prime Arrangements','https://leetcode.com/problems/prime-arrangements/','Medium'],
    ['Distinct Prime Factors of Product (SPF use)','https://leetcode.com/problems/distinct-prime-factors-of-product-of-array/','Medium']
  ]),
  pitfalls: ['Start marking at p*p (smaller multiples are already marked) and stop the outer loop at √n.', 'Use long for p*p to avoid overflow near 2^31.', 'Segmented sieve for ranges [L, R] where R is large but R−L is small.']
},
{
  topic: 'Math & Number Theory', name: 'Modular Exponentiation (+ Inverse)', what: 'Binary exponentiation: square-and-multiply in O(log b) under mod; inverse via Fermat when mod is prime.', when: 'Huge powers (pow(x,n)), combinatorics under mod, "answer can be large, return mod 1e9+7".', tc: 'O(log b)', sc: 'O(1)',
  template: {
    cpp: `long long mpow(long long b, long long e, long long mod) {
    long long r = 1; b %= mod;
    while (e > 0) {
        if (e & 1) r = r * b % mod;
        b = b * b % mod;
        e >>= 1;
    }
    return r;
}
// modular inverse of a under PRIME mod: a^(mod-2) % mod
long long inv(long long a, long long mod) { return mpow(a, mod - 2, mod); }`,
    python: `def mpow(b, e, mod):
    r = 1
    b %= mod
    while e > 0:
        if e & 1: r = r * b % mod
        b = b * b % mod
        e >>= 1
    return r
# pow(b, e, mod) is built-in; inverse: pow(a, -1, mod)`,
    java: `long mpow(long b, long e, long mod) {
    long r = 1; b %= mod;
    while (e > 0) {
        if ((e & 1) == 1) r = r * b % mod;
        b = b * b % mod;
        e >>= 1;
    }
    return r;
}
long inv(long a, long mod) { return mpow(a, mod - 2, mod); }`
  },
  problems: L([
    ['Pow(x, n)','https://leetcode.com/problems/powx-n/','Medium'],
    ['Super Pow','https://leetcode.com/problems/super-pow/','Medium'],
    ['Count Good Numbers','https://leetcode.com/problems/count-good-numbers/','Medium']
  ]),
  pitfalls: ['Take b % mod BEFORE the loop; negative exponents → invert first.', 'Negative n in Pow(x,n): use long long (INT_MIN negation overflows).', 'Fermat inverse only when mod is prime; else use extended Euclid.']
},
{
  topic: 'Math & Number Theory', name: 'nCr / Combinatorics', what: 'Precompute factorials + inverse factorials: nCr = fact[n] × invFact[r] × invFact[n−r] under a prime mod; or Pascal\'s triangle for small n.', when: 'Counting paths, unique paths, pascal\'s triangle, "number of ways" problems under mod.', tc: 'O(n) precompute, O(1) per query', sc: 'O(n)',
  template: {
    cpp: `const long long MOD = 1e9 + 7;
vector<long long> fact(MAXN + 1), invFact(MAXN + 1);
fact[0] = 1;
for (int i = 1; i <= MAXN; i++) fact[i] = fact[i-1] * i % MOD;
invFact[MAXN] = mpow(fact[MAXN], MOD - 2, MOD);          // Fermat
for (int i = MAXN; i >= 1; i--) invFact[i-1] = invFact[i] * i % MOD;
long long nCr(long long n, long long r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
}`,
    python: `MOD = 10**9 + 7
MAXN = 10**6
fact = [1] * (MAXN + 1)
for i in range(1, MAXN + 1):
    fact[i] = fact[i-1] * i % MOD
inv_fact = [1] * (MAXN + 1)
inv_fact[MAXN] = pow(fact[MAXN], MOD - 2, MOD)
for i in range(MAXN, 0, -1):
    inv_fact[i-1] = inv_fact[i] * i % MOD
def nCr(n, r):
    if r < 0 or r > n: return 0
    return fact[n] * inv_fact[r] % MOD * inv_fact[n - r] % MOD`,
    java: `static final long MOD = 1_000_000_007L;
static long[] fact = new long[MAXN + 1], invFact = new long[MAXN + 1];
static void precompute() {
    fact[0] = 1;
    for (int i = 1; i <= MAXN; i++) fact[i] = fact[i-1] * i % MOD;
    invFact[MAXN] = mpow(fact[MAXN], MOD - 2, MOD);
    for (int i = MAXN; i >= 1; i--) invFact[i-1] = invFact[i] * i % MOD;
}
static long nCr(long n, long r) {
    if (r < 0 || r > n) return 0;
    return fact[(int) n] * invFact[(int) r] % MOD * invFact[(int) (n - r)] % MOD;
}`
  },
  problems: L([
    ['Unique Paths','https://leetcode.com/problems/unique-paths/','Medium'],
    ['Pascal\'s Triangle','https://leetcode.com/problems/pascals-triangle/','Easy'],
    ['Number of Music Playlists','https://leetcode.com/problems/number-of-music-playlists/','Hard']
  ]),
  pitfalls: ['Take mod after EVERY multiplication (three mults = two % ops).', 'invFact built backwards: invFact[i-1] = invFact[i] × i.', 'Small n (≤ ~1000): Pascal\'s triangle C[i][j] = C[i-1][j-1] + C[i-1][j] is simpler.']
},

/* ============ STRING ALGORITHMS ============ */
{
  topic: 'String Algorithms', name: 'KMP (Prefix Function / LPS)', what: 'LPS[i] = length of the longest proper prefix of s[:i+1] that is also its suffix; enables O(n+m) matching.', when: 'First occurrence of pattern, find all occurrences, shortest palindrome by prepending, periodic strings.', tc: 'O(n + m)', sc: 'O(m)',
  template: {
    cpp: `vector<int> lps(string& p) {                      // longest proper prefix==suffix
    int m = p.size(); vector<int> lps(m, 0);
    for (int i = 1, len = 0; i < m; ) {
        if (p[i] == p[len]) lps[i++] = ++len;
        else if (len) len = lps[len - 1];
        else lps[i++] = 0;
    }
    return lps;
}
int search(string& s, string& p) {
    vector<int> L = lps(p);
    for (int i = 0, j = 0; i < (int)s.size(); ) {
        if (s[i] == p[j]) { i++; j++; if (j == (int)p.size()) return i - j; }
        else if (j) j = L[j - 1];
        else i++;
    }
    return -1;
}`,
    python: `def lps(p):
    m = len(p); l = [0] * m
    i = length = 0
    while i < m:
        if p[i] == p[length]:
            length += 1; l[i] = length; i += 1
        elif length:
            length = l[length - 1]
        else:
            l[i] = 0; i += 1
    return l
def search(s, p):
    L = lps(p); i = j = 0
    while i < len(s):
        if s[i] == p[j]:
            i += 1; j += 1
            if j == len(p): return i - j
        elif j: j = L[j - 1]
        else: i += 1
    return -1`,
    java: `int[] lps(String p) {
    int m = p.length(); int[] l = new int[m];
    for (int i = 1, len = 0; i < m; ) {
        if (p.charAt(i) == p.charAt(len)) l[i++] = ++len;
        else if (len > 0) len = l[len - 1];
        else l[i++] = 0;
    }
    return l;
}
int search(String s, String p) {
    int[] L = lps(p);
    for (int i = 0, j = 0; i < s.length(); ) {
        if (s.charAt(i) == p.charAt(j)) {
            i++; j++;
            if (j == p.length()) return i - j;
        } else if (j > 0) j = L[j - 1];
        else i++;
    }
    return -1;
}`
  },
  problems: L([
    ['Find the Index of the First Occurrence (strStr)','https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/','Easy'],
    ['Shortest Palindrome','https://leetcode.com/problems/shortest-palindrome/','Hard'],
    ['Repeated String Pattern','https://leetcode.com/problems/repeated-substring-pattern/','Easy']
  ]),
  pitfalls: ['On mismatch, fall back j = LPS[j−1] — never restart from scratch.', 'Repeated substring pattern: s is periodic iff LPS[m−1] > 0 and m % (m − LPS[m−1]) == 0.', 'Shortest palindrome: LPS of (s + \'#\' + reverse(s)).']
},
{
  topic: 'String Algorithms', name: 'Z-Function', what: 'Z[i] = length of the longest substring starting at i that matches the prefix of s.', when: 'Pattern occurrences (with separator), string period, counting prefix matches.', tc: 'O(n)', sc: 'O(n)',
  template: {
    cpp: `vector<int> zfunc(string& s) {
    int n = s.size(); vector<int> z(n, 0);
    int l = 0, r = 0;                       // [l, r) = rightmost match window
    for (int i = 1; i < n; i++) {
        if (i < r) z[i] = min(r - i, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
        if (i + z[i] > r) { l = i; r = i + z[i]; }
    }
    return z;
}
// pattern search: z of (p + '#' + t); z[i] == |p| -> occurrence`,
    python: `def zfunc(s):
    n = len(s); z = [0] * n
    l = r = 0
    for i in range(1, n):
        if i < r: z[i] = min(r - i, z[i - l])
        while i + z[i] < n and s[z[i]] == s[i + z[i]]:
            z[i] += 1
        if i + z[i] > r: l, r = i, i + z[i]
    return z
# search: z of p + '#' + t, count i where z[i] == len(p)`,
    java: `int[] zfunc(String s) {
    int n = s.length(); int[] z = new int[n];
    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        if (i < r) z[i] = Math.min(r - i, z[i - l]);
        while (i + z[i] < n && s.charAt(z[i]) == s.charAt(i + z[i])) z[i]++;
        if (i + z[i] > r) { l = i; r = i + z[i]; }
    }
    return z;
}`
  },
  problems: L([
    ['Z-Algorithm (GFG)','https://www.geeksforgeeks.org/problems/search-pattern-z-algorithm--170645/1','Medium'],
    ['Find the Index of the First Occurrence','https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/','Easy'],
    ['Sum of Scores of Built Strings','https://leetcode.com/problems/sum-of-scores-of-built-strings/','Hard']
  ]),
  pitfalls: ['The [l, r) window is the rightmost match — update it only when i + z[i] > r.', 'KMP and Z are interchangeable for matching; Z is often easier to derive.', 'Use a separator (#) that can\'t occur in either string.']
},
{
  topic: 'String Algorithms', name: 'Rabin-Karp (Rolling Hash)', what: 'Hash every window in O(1) while sliding: h = (h·B + new) − old·B^(m−1); compare hashes, verify on hit.', when: 'Multiple pattern search, plagiarism detection, longest duplicate substring (binary search + hash).', tc: 'O(n + m) expected', sc: 'O(1)',
  template: {
    cpp: `const long long MOD = 1e18 + 9, B = 131;
long long hashOf(string& s, int len) {
    long long h = 0;
    for (int i = 0; i < len; i++) h = (h * B + s[i]) % MOD;
    return h;
}
// rolling: for each new position i (window length m):
// h = (h * B + s[i]) - s[i - m] * pB + MOD*k, then % MOD  (pB = B^(m-1) % MOD)
// ALWAYS verify the actual substring on a hash hit (collisions exist)`,
    python: `MOD, B = (1 << 61) - 1, 131
def hash_of(s, length):
    h = 0
    for i in range(length):
        h = (h * B + ord(s[i])) % MOD
    return h
def rolling(s, m):
    h = hash_of(s, m)
    pB = pow(B, m - 1, MOD)
    yield 0, h
    for i in range(m, len(s)):
        h = ((h - ord(s[i - m]) * pB) * B + ord(s[i])) % MOD
        yield i - m + 1, h
# verify actual substring on hash hit`,
    java: `static final long MOD = (1L << 61) - 1; static final long B = 131;
long hashOf(String s, int len) {
    long h = 0;
    for (int i = 0; i < len; i++) h = (h * B + s.charAt(i)) % MOD;
    return h;
}
// rolling: h = ((h - s[i-m]*pB % MOD + MOD) * B + s[i]) % MOD
// verify substring on hit`
  },
  problems: L([
    ['Longest Duplicate Substring','https://leetcode.com/problems/longest-duplicate-substring/','Hard'],
    ['Repeated DNA Sequences','https://leetcode.com/problems/repeated-dna-sequences/','Medium'],
    ['Longest Chunked Palindrome Decomposition','https://leetcode.com/problems/longest-chunked-palindrome-decomposition/','Hard']
  ]),
  pitfalls: ['Hash collisions are real — always verify candidate matches char by char.', 'Use a large prime mod (or double hashing) to make collisions rare.', 'Careful with negative values after subtraction: add MOD before %.']
},
{
  topic: 'String Algorithms', name: 'Manacher / Expand Around Center', what: 'Every palindrome has a center (2n−1 of them): expand while chars match. Manacher reuses known palindromes for O(n).', when: 'Longest palindromic substring, count palindromic substrings, palindrome partitioning checks.', tc: 'O(n²) expand / O(n) Manacher', sc: 'O(1) / O(n)',
  template: {
    cpp: `pair<int,int> expand(const string& s, int l, int r) {
    while (l >= 0 && r < (int)s.size() && s[l] == s[r]) { l--; r++; }
    return {l + 1, r - 1};                    // inclusive bounds of the palindrome
}
string longestPalindrome(string s) {
    int bestL = 0, bestLen = 0;
    for (int c = 0; c < (int)s.size(); c++) {
        for (int par = 0; par < 2; par++) {   // odd and even centers
            auto [l, r] = expand(s, c - par, c + par);
            if (r - l + 1 > bestLen) { bestLen = r - l + 1; bestL = l; }
        }
    }
    return s.substr(bestL, bestLen);
}`,
    python: `def expand(s, l, r):
    while l >= 0 and r < len(s) and s[l] == s[r]:
        l -= 1; r += 1
    return l + 1, r - 1
def longest_palindrome(s):
    best = ''
    for c in range(len(s)):
        for l, r in (expand(s, c, c), expand(s, c, c + 1)):
            if r - l + 1 > len(best):
                best = s[l:r + 1]
    return best`,
    java: `int[] expand(String s, int l, int r) {
    while (l >= 0 && r < s.length() && s.charAt(l) == s.charAt(r)) { l--; r++; }
    return new int[]{l + 1, r - 1};
}
String longestPalindrome(String s) {
    int bestL = 0, bestLen = 0;
    for (int c = 0; c < s.length(); c++) {
        for (int[] p : new int[][]{expand(s, c, c), expand(s, c, c + 1)}) {
            if (p[1] - p[0] + 1 > bestLen) { bestLen = p[1] - p[0] + 1; bestL = p[0]; }
        }
    }
    return s.substring(bestL, bestL + bestLen);
}`
  },
  problems: L([
    ['Longest Palindromic Substring','https://leetcode.com/problems/longest-palindromic-substring/','Medium'],
    ['Palindromic Substrings (count)','https://leetcode.com/problems/palindromic-substrings/','Medium'],
    ['Valid Palindrome II','https://leetcode.com/problems/valid-palindrome-ii/','Easy']
  ]),
  pitfalls: ['Don\'t forget EVEN-length centers (c, c+1) — the classic missed case.', 'Expand returns (l+1, r-1) because the loop overshoots by one on each side.', 'Manacher: insert separators (#) so odd/even palindromes unify into one array.']
},

/* ============ INTERVALS ============ */
{
  topic: 'Intervals', name: 'Merge Intervals', what: 'Sort by start; merge each interval into the last output interval when it overlaps.', when: 'Merge/insert intervals, overlapping ranges, union of ranges.', tc: 'O(n log n)', sc: 'O(n)',
  template: {
    cpp: `sort(a.begin(), a.end());                 // by start (then end)
vector<vector<int>> out;
for (auto& i : a) {
    if (out.empty() || out.back()[1] < i[0]) out.push_back(i);
    else out.back()[1] = max(out.back()[1], i[1]);   // extend
}`,
    python: `a.sort()
out = []
for s, e in a:
    if not out or out[-1][1] < s:
        out.append([s, e])
    else:
        out[-1][1] = max(out[-1][1], e)`,
    java: `Arrays.sort(a, (x, y) -> Integer.compare(x[0], y[0]));
List<int[]> out = new ArrayList<>();
for (int[] i : a) {
    if (out.isEmpty() || out.get(out.size() - 1)[1] < i[0]) out.add(i);
    else {
        int[] last = out.get(out.size() - 1);
        last[1] = Math.max(last[1], i[1]);
    }
}
return out.toArray(new int[0][]);`
  },
  problems: L([
    ['Merge Intervals','https://leetcode.com/problems/merge-intervals/','Medium'],
    ['Insert Interval','https://leetcode.com/problems/insert-interval/','Medium'],
    ['Meeting Rooms','https://leetcode.com/problems/meeting-rooms/','Easy']
  ]),
  pitfalls: ['Overlap test after sorting: out.back().end >= i.start (use > for "touching" semantics per problem).', 'max() when extending — new interval may be fully contained.', 'Insert Interval: three phases — before, merged overlap, after.']
},
{
  topic: 'Intervals', name: 'Sweep Line / Min-Heaps of End Times', what: 'Events (+1 at start, −1 at end) sorted by time give concurrency; or a min-heap of end times for "how many rooms".', when: 'Meeting rooms II, minimum platforms, car pooling, my calendar I/II.', tc: 'O(n log n)', sc: 'O(n)',
  template: {
    cpp: `// meeting rooms II — min-heap of end times
sort(a.begin(), a.end());                      // by start
priority_queue<int, vector<int>, greater<int>> ends;
int rooms = 0;
for (auto& m : a) {
    while (!ends.empty() && ends.top() <= m[0]) ends.pop();  // reuse freed rooms
    ends.push(m[1]);
    rooms = max(rooms, (int)ends.size());
}
// sweep alternative: sort all events, +1/-1, track running max`,
    python: `import heapq
a.sort()
ends = []      # min-heap of end times
rooms = 0
for s, e in a:
    while ends and ends[0] <= s:
        heapq.heappop(ends)
    heapq.heappush(ends, e)
    rooms = max(rooms, len(ends))`,
    java: `Arrays.sort(a, (x, y) -> Integer.compare(x[0], y[0]));
PriorityQueue<Integer> ends = new PriorityQueue<>();
int rooms = 0;
for (int[] m : a) {
    while (!ends.isEmpty() && ends.peek() <= m[0]) ends.poll();
    ends.offer(m[1]);
    rooms = Math.max(rooms, ends.size());
}`
  },
  problems: L([
    ['Meeting Rooms II','https://leetcode.com/problems/meeting-rooms-ii/','Medium'],
    ['Minimum Platforms (GFG)','https://www.geeksforgeeks.org/problems/minimum-platforms-1587115620/1','Medium'],
    ['Car Pooling','https://leetcode.com/problems/car-pooling/','Medium'],
    ['My Calendar I','https://leetcode.com/problems/my-calendar-i/','Medium']
  ]),
  pitfalls: ['Free a room when end <= start (<= not <) — check the problem\'s boundary convention.', 'Sweep: sort events; when a start and end collide at the same timestamp, process the END first.', 'Car pooling: difference array over stations is O(n + maxStation).']
},

/* ============ MATRIX ============ */
{
  topic: 'Matrix', name: 'Matrix Traversal Patterns (Spiral, Rotate, Set Zeroes)', what: 'Layer-by-layer bounds (spiral), transpose+reverse (rotate), first row/col as flags (set zeroes).', when: 'Spiral matrix, rotate image, set matrix zeroes, diagonal traversal.', tc: 'O(R·C)', sc: 'O(1) for in-place variants',
  template: {
    cpp: `// rotate image 90° clockwise = transpose then reverse each row
for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++) swap(a[i][j], a[j][i]);
for (int i = 0; i < n; i++) reverse(a[i].begin(), a[i].end());

// set zeroes in place: use row0/col0 as flags
bool row0 = false, col0 = false;
for (int j = 0; j < C; j++) if (a[0][j] == 0) row0 = true;
for (int i = 0; i < R; i++) if (a[i][0] == 0) col0 = true;
for (int i = 1; i < R; i++) for (int j = 1; j < C; j++)
    if (a[i][j] == 0) { a[i][0] = 0; a[0][j] = 0; }
for (int i = 1; i < R; i++) for (int j = 1; j < C; j++)
    if (a[i][0] == 0 || a[0][j] == 0) a[i][j] = 0;
if (row0) for (int j = 0; j < C; j++) a[0][j] = 0;
if (col0) for (int i = 0; i < R; i++) a[i][0] = 0;`,
    python: `# rotate: transpose then reverse each row
for i in range(n):
    for j in range(i + 1, n):
        a[i][j], a[j][i] = a[j][i], a[i][j]
for row in a:
    row.reverse()
# set zeroes: same flags trick as C++`,
    java: `// rotate: transpose then reverse each row
for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++) { int t = a[i][j]; a[i][j] = a[j][i]; a[j][i] = t; }
for (int[] row : a) {
    for (int l = 0, r = row.length - 1; l < r; l++, r--) {
        int t = row[l]; row[l] = row[r]; row[r] = t;
    }
}`
  },
  problems: L([
    ['Rotate Image','https://leetcode.com/problems/rotate-image/','Medium'],
    ['Spiral Matrix','https://leetcode.com/problems/spiral-matrix/','Medium'],
    ['Set Matrix Zeroes','https://leetcode.com/problems/set-matrix-zeroes/','Medium'],
    ['Search a 2D Matrix II','https://leetcode.com/problems/search-a-2d-matrix-ii/','Medium']
  ]),
  pitfalls: ['Rotate: transpose (not reverse-then-transpose) for clockwise; counter-clockwise is the other order.', 'Spiral: shrink top/bottom/left/right after each pass; check bounds between passes for single row/column.', 'Search in row & column sorted matrix: start at top-right corner — O(R + C).']
},

/* ============ MISCELLANEOUS ============ */
{
  topic: 'Miscellaneous', name: 'Dutch National Flag (Sort 0s, 1s, 2s)', what: 'Three pointers (low, mid, high) partition in one pass: swap 0s left, 2s right, mid scans.', when: 'Sort colors, three-way partition, quicksort 3-way pivot handling.', tc: 'O(n)', sc: 'O(1)',
  template: {
    cpp: `int low = 0, mid = 0, high = n - 1;
while (mid <= high) {
    if (a[mid] == 0)      swap(a[low++], a[mid++]);
    else if (a[mid] == 1) mid++;
    else                  swap(a[mid], a[high--]);   // don't advance mid here!
}`,
    python: `low = mid = 0
high = len(a) - 1
while mid <= high:
    if a[mid] == 0:
        a[low], a[mid] = a[mid], a[low]
        low += 1; mid += 1
    elif a[mid] == 1:
        mid += 1
    else:
        a[mid], a[high] = a[high], a[mid]
        high -= 1          # do NOT advance mid — new a[mid] is unchecked`,
    java: `int low = 0, mid = 0, high = n - 1;
while (mid <= high) {
    if (a[mid] == 0)      { int t = a[low]; a[low++] = a[mid]; a[mid++] = t; }
    else if (a[mid] == 1) mid++;
    else                  { int t = a[mid]; a[mid] = a[high]; a[high--] = t; }
}`
  },
  problems: L([
    ['Sort Colors','https://leetcode.com/problems/sort-colors/','Medium'],
    ['Sort List of 0s, 1s and 2s (GFG)','https://www.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1','Easy']
  ]),
  pitfalls: ['After swapping with high, do NOT increment mid — the swapped-in element is unexamined.', 'Loop condition is mid <= high (high shrinks).']
},
{
  topic: 'Miscellaneous', name: 'Moore\'s Voting (Majority Element)', what: 'Keep a candidate + counter; a different element decrements, same increments. The true majority survives.', when: 'Majority element > n/2 (verify-free), > n/3 (need two candidates + final verification).', tc: 'O(n)', sc: 'O(1)',
  template: {
    cpp: `// > n/2
int cand = 0, cnt = 0;
for (int v : a) {
    if (cnt == 0) cand = v;
    cnt += (v == cand) ? 1 : -1;
}
// for > n/3: keep two candidates c1,c2 with counts; then VERIFY both counts > n/3`,
    python: `cand, cnt = None, 0
for v in a:
    if cnt == 0:
        cand = v
    cnt += 1 if v == cand else -1
# for > n/3: two candidates + final verification pass`,
    java: `int cand = 0, cnt = 0;
for (int v : a) {
    if (cnt == 0) cand = v;
    cnt += (v == cand) ? 1 : -1;
}
// for > n/3: two candidates + verification`
  },
  problems: L([
    ['Majority Element','https://leetcode.com/problems/majority-element/','Easy'],
    ['Majority Element II (> n/3)','https://leetcode.com/problems/majority-element-ii/','Medium']
  ]),
  pitfalls: ['For > n/3 there can be AT MOST 2 candidates — verify both with a final count pass (candidate can be wrong when no majority exists).', 'Works only for strict majorities (> n/2, > n/3); not for "most frequent".']
},
{
  topic: 'Miscellaneous', name: 'Kadane\'s Algorithm (Max Subarray Sum)', what: 'Extend the running sum or restart at i, whichever is larger: cur = max(a[i], cur + a[i]).', when: 'Maximum subarray, max circular subarray, minimum subarray (negate), max product (track min too).', tc: 'O(n)', sc: 'O(1)',
  template: {
    cpp: `long long best = a[0], cur = a[0];
for (int i = 1; i < n; i++) {
    cur = max((long long)a[i], cur + a[i]);   // restart or extend
    best = max(best, cur);
}
// max circular: total - minSubarray (careful: all-negative case)
// max product: track (maxProd, minProd) — min can flip sign to max`,
    python: `best = cur = a[0]
for i in range(1, len(a)):
    cur = max(a[i], cur + a[i])
    best = max(best, cur)
# max circular: total - min_subarray (handle all-negative)`,
    java: `long best = a[0], cur = a[0];
for (int i = 1; i < n; i++) {
    cur = Math.max(a[i], cur + a[i]);
    best = Math.max(best, cur);
}`
  },
  problems: L([
    ['Maximum Subarray','https://leetcode.com/problems/maximum-subarray/','Medium'],
    ['Maximum Sum Circular Subarray','https://leetcode.com/problems/maximum-sum-circular-subarray/','Medium'],
    ['Maximum Product Subarray','https://leetcode.com/problems/maximum-product-subarray/','Medium']
  ]),
  pitfalls: ['Initialize best AND cur with a[0], not 0 (fails on all-negative arrays).', 'Max product needs BOTH max and min running products (negatives flip).', 'Circular: if minSubarray == total (all negative), answer is max element, not 0.']
},
{
  topic: 'Miscellaneous', name: 'Next Permutation', what: 'Find the longest non-increasing suffix, swap the pivot with the smallest larger suffix element, reverse the suffix.', when: 'Next permutation, previous permutation (mirror logic), kth permutation.', tc: 'O(n)', sc: 'O(1)',
  template: {
    cpp: `int i = n - 2;
while (i >= 0 && a[i] >= a[i + 1]) i--;       // pivot = first element < its next
if (i >= 0) {
    int j = n - 1;
    while (a[j] <= a[i]) j--;                 // smallest element greater than pivot
    swap(a[i], a[j]);
}
reverse(a.begin() + i + 1, a.end());          // suffix was non-increasing -> reverse`,
    python: `i = len(a) - 2
while i >= 0 and a[i] >= a[i + 1]:
    i -= 1
if i >= 0:
    j = len(a) - 1
    while a[j] <= a[i]:
        j -= 1
    a[i], a[j] = a[j], a[i]
a[i + 1:] = reversed(a[i + 1:])`,
    java: `int i = n - 2;
while (i >= 0 && a[i] >= a[i + 1]) i--;
if (i >= 0) {
    int j = n - 1;
    while (a[j] <= a[i]) j--;
    int t = a[i]; a[i] = a[j]; a[j] = t;
}
for (int l = i + 1, r = n - 1; l < r; l++, r--) {
    int t = a[l]; a[l] = a[r]; a[r] = t;
}`
  },
  problems: L([
    ['Next Permutation','https://leetcode.com/problems/next-permutation/','Medium'],
    ['Permutation Sequence','https://leetcode.com/problems/permutation-sequence/','Hard']
  ]),
  pitfalls: ['If the whole array is non-increasing, i < 0 → just reverse everything (first permutation).', 'Scan j from the right; a[j] > a[i] is enough because the suffix is non-increasing.', 'Reverse, don\'t sort the suffix — it\'s already in the right order.']
}
];

/* -------- "Problems I should solve next" — NOT in the user's directory -------- */
const suggested = [
  { topic: 'Arrays & Hashing', items: L([
    ['Longest Consecutive Sequence','https://leetcode.com/problems/longest-consecutive-sequence/','Medium'],
    ['Product of Array Except Self','https://leetcode.com/problems/product-of-array-except-self/','Medium'],
    ['First Missing Positive','https://leetcode.com/problems/first-missing-positive/','Hard']
  ])},
  { topic: 'Sliding Window', items: L([
    ['Minimum Window Substring','https://leetcode.com/problems/minimum-window-substring/','Hard'],
    ['Sliding Window Maximum','https://leetcode.com/problems/sliding-window-maximum/','Hard']
  ])},
  { topic: 'Two Pointers', items: L([
    ['Trapping Rain Water','https://leetcode.com/problems/trapping-rain-water/','Hard'],
    ['4Sum','https://leetcode.com/problems/4sum/','Medium']
  ])},
  { topic: 'Binary Search', items: L([
    ['Median of Two Sorted Arrays','https://leetcode.com/problems/median-of-two-sorted-arrays/','Hard'],
    ['Koko Eating Bananas','https://leetcode.com/problems/koko-eating-bananas/','Medium'],
    ['Median of Two Sorted Arrays','https://leetcode.com/problems/median-of-two-sorted-arrays/','Hard']
  ])},
  { topic: 'Stack & Queue', items: L([
    ['Largest Rectangle in Histogram','https://leetcode.com/problems/largest-rectangle-in-histogram/','Hard'],
    ['Trapping Rain Water','https://leetcode.com/problems/trapping-rain-water/','Hard']
  ])},
  { topic: 'Heap / Priority Queue', items: L([
    ['Find Median from Data Stream','https://leetcode.com/problems/find-median-from-data-stream/','Hard'],
    ['Merge k Sorted Lists','https://leetcode.com/problems/merge-k-sorted-lists/','Hard'],
    ['Reorganize String','https://leetcode.com/problems/reorganize-string/','Medium']
  ])},
  { topic: 'Trees & BST', items: L([
    ['Serialize and Deserialize Binary Tree','https://leetcode.com/problems/serialize-and-deserialize-binary-tree/','Hard'],
    ['Binary Tree Maximum Path Sum','https://leetcode.com/problems/binary-tree-maximum-path-sum/','Hard'],
    ['Populating Next Right Pointers','https://leetcode.com/problems/populating-next-right-pointers-in-each-node/','Medium']
  ])},
  { topic: 'Graphs', items: L([
    ['Word Ladder','https://leetcode.com/problems/word-ladder/','Hard'],
    ['Alien Dictionary','https://leetcode.com/problems/alien-dictionary/','Hard'],
    ['Min Cost to Connect All Points','https://leetcode.com/problems/min-cost-to-connect-all-points/','Medium'],
    ['Number of Ways to Arrive at Destination','https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/','Medium']
  ])},
  { topic: 'Dynamic Programming', items: L([
    ['Burst Balloons','https://leetcode.com/problems/burst-balloons/','Hard'],
    ['Regular Expression Matching','https://leetcode.com/problems/regular-expression-matching/','Hard'],
    ['Best Time to Buy and Sell Stock III','https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/','Hard'],
    ['Word Break','https://leetcode.com/problems/word-break/','Medium']
  ])},
  { topic: 'String Algorithms', items: L([
    ['Shortest Palindrome','https://leetcode.com/problems/shortest-palindrome/','Hard'],
    ['Longest Duplicate Substring','https://leetcode.com/problems/longest-duplicate-substring/','Hard']
  ])},
  { topic: 'Intervals', items: L([
    ['Meeting Rooms II','https://leetcode.com/problems/meeting-rooms-ii/','Medium'],
    ['Minimum Number of Arrows to Burst Balloons','https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/','Medium']
  ])},
  { topic: 'Math & Number Theory', items: L([
    ['Count Primes','https://leetcode.com/problems/count-primes/','Medium'],
    ['Pow(x, n)','https://leetcode.com/problems/powx-n/','Medium']
  ])}
];

module.exports = { algorithms, suggested };

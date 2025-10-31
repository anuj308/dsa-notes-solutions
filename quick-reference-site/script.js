// Data for Git Commands
const gitCommands = [
    { cmd: 'git init', desc: 'Initialize a new Git repository' },
    { cmd: 'git clone <url>', desc: 'Clone a repository from URL' },
    { cmd: 'git status', desc: 'Check status of working directory' },
    { cmd: 'git add .', desc: 'Stage all changes' },
    { cmd: 'git add <file>', desc: 'Stage specific file' },
    { cmd: 'git commit -m "message"', desc: 'Commit staged changes with message' },
    { cmd: 'git commit -am "message"', desc: 'Stage and commit all changes' },
    { cmd: 'git push', desc: 'Push commits to remote repository' },
    { cmd: 'git push origin <branch>', desc: 'Push to specific branch' },
    { cmd: 'git pull', desc: 'Fetch and merge changes from remote' },
    { cmd: 'git fetch', desc: 'Download changes without merging' },
    { cmd: 'git branch', desc: 'List all local branches' },
    { cmd: 'git branch <name>', desc: 'Create new branch' },
    { cmd: 'git checkout <branch>', desc: 'Switch to branch' },
    { cmd: 'git checkout -b <branch>', desc: 'Create and switch to new branch' },
    { cmd: 'git merge <branch>', desc: 'Merge branch into current branch' },
    { cmd: 'git log', desc: 'View commit history' },
    { cmd: 'git log --oneline', desc: 'Compact commit history' },
    { cmd: 'git diff', desc: 'Show unstaged changes' },
    { cmd: 'git diff --staged', desc: 'Show staged changes' },
    { cmd: 'git reset <file>', desc: 'Unstage file' },
    { cmd: 'git reset --hard', desc: 'Discard all changes (careful!)' },
    { cmd: 'git stash', desc: 'Temporarily save changes' },
    { cmd: 'git stash pop', desc: 'Apply stashed changes' },
    { cmd: 'git remote -v', desc: 'Show remote repositories' },
    { cmd: 'git remote add origin <url>', desc: 'Add remote repository' },
];

// Data for Linux Commands
const linuxCommands = [
    { cmd: 'ls', desc: 'List directory contents' },
    { cmd: 'ls -la', desc: 'List all files with details' },
    { cmd: 'cd <directory>', desc: 'Change directory' },
    { cmd: 'cd ..', desc: 'Go to parent directory' },
    { cmd: 'pwd', desc: 'Print working directory' },
    { cmd: 'mkdir <name>', desc: 'Create directory' },
    { cmd: 'mkdir -p <path>', desc: 'Create nested directories' },
    { cmd: 'rm <file>', desc: 'Remove file' },
    { cmd: 'rm -rf <directory>', desc: 'Remove directory recursively (careful!)' },
    { cmd: 'cp <source> <dest>', desc: 'Copy file' },
    { cmd: 'cp -r <source> <dest>', desc: 'Copy directory recursively' },
    { cmd: 'mv <source> <dest>', desc: 'Move or rename file/directory' },
    { cmd: 'cat <file>', desc: 'Display file contents' },
    { cmd: 'less <file>', desc: 'View file with pagination' },
    { cmd: 'head <file>', desc: 'Show first 10 lines' },
    { cmd: 'tail <file>', desc: 'Show last 10 lines' },
    { cmd: 'grep "pattern" file', desc: 'Search for pattern in file' },
    { cmd: 'find . -name "*.cpp"', desc: 'Find all .cpp files' },
    { cmd: 'chmod +x <file>', desc: 'Make file executable' },
    { cmd: 'chmod 755 <file>', desc: 'Set file permissions' },
    { cmd: 'ps aux', desc: 'List all running processes' },
    { cmd: 'kill <pid>', desc: 'Kill process by ID' },
    { cmd: 'top', desc: 'Display running processes' },
    { cmd: 'df -h', desc: 'Show disk usage' },
    { cmd: 'du -sh <directory>', desc: 'Show directory size' },
    { cmd: 'tar -czf archive.tar.gz <dir>', desc: 'Create compressed archive' },
    { cmd: 'tar -xzf archive.tar.gz', desc: 'Extract compressed archive' },
];

// Data for DSA Topics
const dsaTopics = [
    { 
        name: 'Arrays', 
        icon: '📊', 
        files: ['06arraylargest.cpp', '07ArraysPart2.cpp', '08ArraysPart3.cpp', '09ArraysPart4.cpp'],
        folder: 'tuf',
        count: 7
    },
    { 
        name: 'Binary Search', 
        icon: '🔍', 
        files: ['12BinarySearchEasy.cpp', '13BinarySearchMedium.cpp', '14BinarySearchHard.cpp'],
        folder: 'tuf',
        count: 14
    },
    { 
        name: 'Linked Lists', 
        icon: '🔗', 
        files: ['16LinkListBasic.cpp', '17LinkListMedium.cpp'],
        folder: 'tuf',
        count: 5
    },
    { 
        name: 'Trees', 
        icon: '🌳', 
        files: ['25BinaryTreePart1.cpp', '26BinaryTreePart2.cpp', '27BinarySeacrchTree.cpp'],
        folder: 'tuf',
        count: 12
    },
    { 
        name: 'Graphs', 
        icon: '🕸️', 
        files: ['28GraphPart1.cpp', '29GraphPart2.cpp', '30GraphPart3.cpp', '31GraphPart4.cpp'],
        folder: 'tuf',
        count: 9
    },
    { 
        name: 'Dynamic Programming', 
        icon: '🎯', 
        files: ['24Dp.cpp'],
        folder: 'tuf',
        count: 3
    },
    { 
        name: 'Stacks & Queues', 
        icon: '📚', 
        files: ['21Stack&Queue.cpp'],
        folder: 'tuf',
        count: 4
    },
    { 
        name: 'Heaps', 
        icon: '⛰️', 
        files: ['Heap problems in notes.txt'],
        folder: 'notes',
        count: 6
    },
    { 
        name: 'Strings', 
        icon: '📝', 
        files: ['15String.cpp'],
        folder: 'tuf',
        count: 6
    },
    { 
        name: 'LeetCode Daily', 
        icon: '📅', 
        files: ['All problems in LeetcodeDaliy folder'],
        folder: 'LeetcodeDaliy',
        count: 35
    },
];

// Code Templates
const codeTemplates = [
    {
        title: 'Binary Search Template',
        language: 'cpp',
        code: `int binarySearch(vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    
    return -1; // Not found
}`
    },
    {
        title: 'DFS Graph Traversal',
        language: 'cpp',
        code: `void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;
    
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited);
        }
    }
}`
    },
    {
        title: 'BFS Graph Traversal',
        language: 'cpp',
        code: `void bfs(int start, vector<vector<int>>& adj) {
    vector<bool> visited(adj.size(), false);
    queue<int> q;
    
    q.push(start);
    visited[start] = true;
    
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}`
    },
    {
        title: 'Max Heap Implementation',
        language: 'cpp',
        code: `void maxHeapify(vector<int>& heap, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    
    if (left < n && heap[left] > heap[largest])
        largest = left;
    
    if (right < n && heap[right] > heap[largest])
        largest = right;
    
    if (largest != i) {
        swap(heap[i], heap[largest]);
        maxHeapify(heap, n, largest);
    }
}`
    },
    {
        title: 'Sliding Window Template',
        language: 'cpp',
        code: `int slidingWindow(vector<int>& arr, int k) {
    int left = 0, right = 0;
    int windowSum = 0, maxSum = 0;
    
    while (right < arr.size()) {
        windowSum += arr[right];
        
        if (right - left + 1 == k) {
            maxSum = max(maxSum, windowSum);
            windowSum -= arr[left];
            left++;
        }
        right++;
    }
    
    return maxSum;
}`
    },
];

// Web Dev Notes
const webNotes = [
    {
        title: 'React Hooks',
        items: [
            'useState - Manage component state',
            'useEffect - Side effects (API calls, subscriptions)',
            'useContext - Access context values',
            'useRef - Reference DOM elements',
            'useMemo - Memoize expensive calculations',
            'useCallback - Memoize functions',
        ]
    },
    {
        title: 'Node.js Essentials',
        items: [
            'Express.js - Web framework',
            'Middleware - Request/response processing',
            'Routing - Define API endpoints',
            'MongoDB/Mongoose - Database integration',
            'JWT - Authentication',
            'bcrypt - Password hashing',
        ]
    },
    {
        title: 'TypeScript Basics',
        items: [
            'Types: string, number, boolean, array',
            'Interfaces - Define object shapes',
            'Type aliases - Custom types',
            'Generics - Reusable components',
            'Union types - Multiple possible types',
            'Optional properties - field?',
        ]
    },
    {
        title: 'Useful Links',
        items: [
            '<a href="https://github.com/anuj308/dsac-/blob/main/React/notes.md" target="_blank" class="text-blue-600 hover:underline">React Notes →</a>',
            '<a href="https://github.com/anuj308/dsac-/blob/main/Nodejs/notes.md" target="_blank" class="text-blue-600 hover:underline">Node.js Notes →</a>',
        ]
    },
];

// Initialize Page
document.addEventListener('DOMContentLoaded', () => {
    populateGitCommands();
    populateLinuxCommands();
    populateDSATopics();
    populateCodeTemplates();
    populateWebNotes();
    setupSearch();
    setupDarkMode();
});

// Populate Git Commands
function populateGitCommands() {
    const tbody = document.getElementById('gitCommands');
    tbody.innerHTML = gitCommands.map(item => `
        <tr class="hover:bg-gray-50 dark:hover:bg-gray-700 searchable-item">
            <td class="px-6 py-4 whitespace-nowrap">
                <code class="text-sm font-mono text-blue-600 dark:text-blue-400">${item.cmd}</code>
            </td>
            <td class="px-6 py-4 text-sm text-gray-600 dark:text-gray-300">${item.desc}</td>
            <td class="px-6 py-4">
                <button onclick="copyToClipboard('${item.cmd}')" class="text-gray-400 hover:text-blue-600 transition-colors">
                    📋
                </button>
            </td>
        </tr>
    `).join('');
}

// Populate Linux Commands
function populateLinuxCommands() {
    const tbody = document.getElementById('linuxCommands');
    tbody.innerHTML = linuxCommands.map(item => `
        <tr class="hover:bg-gray-50 dark:hover:bg-gray-700 searchable-item">
            <td class="px-6 py-4 whitespace-nowrap">
                <code class="text-sm font-mono text-green-600 dark:text-green-400">${item.cmd}</code>
            </td>
            <td class="px-6 py-4 text-sm text-gray-600 dark:text-gray-300">${item.desc}</td>
            <td class="px-6 py-4">
                <button onclick="copyToClipboard('${item.cmd}')" class="text-gray-400 hover:text-green-600 transition-colors">
                    📋
                </button>
            </td>
        </tr>
    `).join('');
}

// Populate DSA Topics
function populateDSATopics() {
    const container = document.getElementById('dsaTopics');
    container.innerHTML = dsaTopics.map(topic => {
        // Determine the link - if first file exists and is a real file, link to it, otherwise link to folder
        let link = `https://github.com/anuj308/dsac-/tree/main/${topic.folder}`;
        if (topic.files[0] && !topic.files[0].includes('problems in') && !topic.files[0].includes('All problems')) {
            // Link to first file
            link = `https://github.com/anuj308/dsac-/blob/main/${topic.folder}/${topic.files[0]}`;
        }
        
        return `
        <div class="bg-white dark:bg-gray-800 rounded-lg shadow p-6 hover:shadow-lg transition-shadow searchable-item">
            <div class="flex items-center justify-between mb-3">
                <h3 class="text-lg font-semibold text-gray-900 dark:text-white flex items-center gap-2">
                    <span class="text-2xl">${topic.icon}</span>
                    ${topic.name}
                </h3>
                <span class="px-2 py-1 bg-blue-100 dark:bg-blue-900 text-blue-600 dark:text-blue-300 text-xs rounded-full">
                    ${topic.count}
                </span>
            </div>
            <div class="text-sm text-gray-600 dark:text-gray-400 mb-3">
                ${topic.files.length} file(s) in <code class="text-xs bg-gray-100 dark:bg-gray-700 px-2 py-1 rounded">${topic.folder}/</code>
            </div>
            <a href="${link}" 
               target="_blank" 
               class="inline-flex items-center text-sm text-blue-600 dark:text-blue-400 hover:underline">
                View on GitHub →
            </a>
        </div>
        `;
    }).join('');
}

// Populate Code Templates
function populateCodeTemplates() {
    const container = document.getElementById('codeTemplates');
    container.innerHTML = codeTemplates.map((template, index) => `
        <div class="bg-white dark:bg-gray-800 rounded-lg shadow overflow-hidden searchable-item">
            <div class="px-6 py-4 bg-gray-50 dark:bg-gray-700 flex items-center justify-between">
                <h3 class="text-lg font-semibold text-gray-900 dark:text-white">${template.title}</h3>
                <button onclick="copyCode(${index})" class="px-3 py-1 bg-blue-600 text-white text-sm rounded hover:bg-blue-700 transition-colors">
                    📋 Copy
                </button>
            </div>
            <div class="relative code-container">
                <pre class="p-6 overflow-x-auto"><code class="language-${template.language}">${escapeHtml(template.code)}</code></pre>
            </div>
        </div>
    `).join('');
    
    // Re-highlight code
    Prism.highlightAll();
}

// Populate Web Notes
function populateWebNotes() {
    const container = document.getElementById('webNotes');
    container.innerHTML = webNotes.map(note => `
        <div class="bg-white dark:bg-gray-800 rounded-lg shadow p-6 searchable-item">
            <h3 class="text-lg font-semibold text-gray-900 dark:text-white mb-4">${note.title}</h3>
            <ul class="space-y-2">
                ${note.items.map(item => `
                    <li class="text-sm text-gray-600 dark:text-gray-300 flex items-start gap-2">
                        <span class="text-blue-600 mt-1">▸</span>
                        <span>${item}</span>
                    </li>
                `).join('')}
            </ul>
        </div>
    `).join('');
}

// Copy to Clipboard
function copyToClipboard(text) {
    navigator.clipboard.writeText(text).then(() => {
        showToast('Copied to clipboard!');
    }).catch(err => {
        console.error('Failed to copy:', err);
    });
}

// Copy Code Template
function copyCode(index) {
    const code = codeTemplates[index].code;
    copyToClipboard(code);
}

// Show Toast Notification
function showToast(message) {
    const toast = document.createElement('div');
    toast.className = 'fixed bottom-4 right-4 bg-green-600 text-white px-6 py-3 rounded-lg shadow-lg z-50 animate-fade-in';
    toast.textContent = message;
    document.body.appendChild(toast);
    
    setTimeout(() => {
        toast.remove();
    }, 2000);
}

// Search Functionality
function setupSearch() {
    const searchInput = document.getElementById('searchInput');
    
    searchInput.addEventListener('input', (e) => {
        const query = e.target.value.toLowerCase();
        const items = document.querySelectorAll('.searchable-item');
        
        items.forEach(item => {
            const text = item.textContent.toLowerCase();
            if (text.includes(query)) {
                item.style.display = '';
                item.classList.remove('hidden');
            } else {
                item.style.display = 'none';
                item.classList.add('hidden');
            }
        });
    });
}

// Dark Mode Toggle
function setupDarkMode() {
    const toggle = document.getElementById('darkModeToggle');
    const html = document.documentElement;
    
    // Check saved preference
    const isDark = localStorage.getItem('darkMode') === 'true';
    if (isDark) {
        html.classList.add('dark');
        toggle.textContent = '☀️';
    }
    
    toggle.addEventListener('click', () => {
        html.classList.toggle('dark');
        const isDark = html.classList.contains('dark');
        localStorage.setItem('darkMode', isDark);
        toggle.textContent = isDark ? '☀️' : '🌙';
    });
}

// Escape HTML
function escapeHtml(text) {
    const map = {
        '&': '&amp;',
        '<': '&lt;',
        '>': '&gt;',
        '"': '&quot;',
        "'": '&#039;'
    };
    return text.replace(/[&<>"']/g, m => map[m]);
}

// Add CSS animation
const style = document.createElement('style');
style.textContent = `
    @keyframes fade-in {
        from { opacity: 0; transform: translateY(10px); }
        to { opacity: 1; transform: translateY(0); }
    }
    .animate-fade-in {
        animation: fade-in 0.3s ease-out;
    }
`;
document.head.appendChild(style);

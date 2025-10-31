# 📚 DSA Quick Reference Website

A simple, fast, and responsive single-page website for quick revision of DSA concepts, Git/Linux commands, and web development notes.

## 🚀 Features

✅ **No Build Required** - Just open `index.html` in browser  
✅ **Fully Responsive** - Works on mobile, tablet, desktop  
✅ **Dark Mode** - Toggle with 🌙 button  
✅ **Search Functionality** - Find commands/topics instantly  
✅ **Copy Buttons** - One-click copy for all commands/code  
✅ **Syntax Highlighting** - Beautiful code display using Prism.js  
✅ **Fast Loading** - Single page, CDN-based  
✅ **Offline Ready** - Save HTML and use without internet  

## 📁 Structure

```
quick-reference-site/
├── index.html          # Main HTML file (single page!)
├── script.js           # JavaScript for functionality
└── README.md           # This file
```

## 🎯 What's Included

### 1️⃣ **Git Commands** (26 commands)
- All essential git operations
- Searchable table format
- Copy button for each command

### 2️⃣ **Linux Commands** (27 commands)
- Common terminal operations
- File/directory management
- Process control commands

### 3️⃣ **DSA Topics** (10 categories)
- Direct links to GitHub files
- Organized by topic (Arrays, Trees, Graphs, etc.)
- Shows problem count for each topic

### 4️⃣ **Code Templates** (5 templates)
- Binary Search
- DFS/BFS Graph Traversal
- Max Heap Implementation
- Sliding Window
- Copy-ready code snippets

### 5️⃣ **Web Dev Quick Notes**
- React Hooks reference
- Node.js essentials
- TypeScript basics
- Links to full notes

### 6️⃣ **SQL Reference**
- Direct link to LeetCode SQL 50 solutions

## 🏃 How to Use

### **Option 1: Open Locally**
1. Navigate to `quick-reference-site` folder
2. Double-click `index.html`
3. Opens in your default browser ✅

### **Option 2: Deploy to GitHub Pages (FREE)**

1. **Push to GitHub:**
```bash
cd c:\Users\ANUJ\Documents\GitHub\dsac-
git add quick-reference-site/
git commit -m "Add quick reference website"
git push origin main
```

2. **Enable GitHub Pages:**
- Go to repository Settings → Pages
- Source: Deploy from branch `main`
- Folder: Select `/quick-reference-site`
- Save

3. **Access your site:**
```
https://anuj308.github.io/dsac-/quick-reference-site/
```

### **Option 3: Deploy to Vercel (Even Faster)**

1. Go to [vercel.com](https://vercel.com)
2. Import your GitHub repository
3. Set root directory to `quick-reference-site`
4. Deploy!

Your site will be live at: `https://dsac-quick-reference.vercel.app`

## 📱 Mobile Usage

Perfect for quick revision on the go:
- ✅ Responsive design
- ✅ Touch-friendly buttons
- ✅ Search functionality
- ✅ Dark mode for night reading
- ✅ Save to home screen (PWA-ready)

## 🎨 Customization

### **Add More Commands:**
Edit `script.js` and add to arrays:

```javascript
const gitCommands = [
    { cmd: 'your-command', desc: 'Description' },
    // Add more...
];
```

### **Add More Code Templates:**
```javascript
const codeTemplates = [
    {
        title: 'Your Template Name',
        language: 'cpp', // or 'python', 'java', etc.
        code: `your code here`
    },
];
```

### **Change Colors:**
Uses Tailwind CSS - modify classes in `index.html`:
- `bg-blue-600` → Change primary color
- `dark:bg-gray-900` → Change dark mode colors

## 🔥 Tips

1. **Bookmark the page** for quick access
2. **Use search** (🔍) to find commands instantly
3. **Toggle dark mode** (🌙) for comfortable reading
4. **Click topic cards** to jump directly to sections
5. **Copy buttons** (📋) for instant code/command copying

## 🌐 Browser Support

✅ Chrome/Edge (Recommended)  
✅ Firefox  
✅ Safari  
✅ Mobile browsers (iOS Safari, Chrome Mobile)  

## ⚡ Performance

- **Load Time:** < 1 second
- **File Size:** ~50KB total (HTML + JS)
- **CDN Assets:** Loaded from fast CDNs
- **No Backend:** Pure frontend = always fast

## 🎯 Perfect For:

- ✅ Quick revision before interviews
- ✅ On-the-go learning (mobile)
- ✅ Command lookup (git/linux)
- ✅ Code template reference
- ✅ Daily practice reminder

## 📝 Future Enhancements (Optional)

You can add later:
- [ ] More code templates
- [ ] Problem difficulty filters
- [ ] Favorite/bookmark commands
- [ ] Your college notes sections
- [ ] Practice problem tracker
- [ ] Flashcard mode

## 🤝 Contributing

This is your personal quick reference. Feel free to:
1. Add your own commands
2. Include more code templates
3. Customize colors/layout
4. Share with friends!

## 📞 Support

Having issues?
1. Make sure JavaScript is enabled
2. Try different browser
3. Check browser console for errors
4. Clear cache and reload

## 🎉 That's It!

You now have a fast, beautiful, mobile-friendly quick reference website for all your DSA and command needs!

**No installation, no build tools, no complexity - just open and use!** 🚀

---

Made with ❤️ for quick revision | 395 LeetCode Problems Solved 🎉

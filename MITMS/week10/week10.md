## Week 10 Search Engines and web

### 1. Setup custom search shortcuts:
```https://www.youtube.com/results?search_query=%s```

### 3. Styling
I was not interested in changing per site css (though the idea is cool). 
Instead I wanted to change the tab css that affects all of firefox. 
Opting to remove the "x" button, as this is a common fix I see people make to their browsers, I did the following:
changed `toolkit.legacyUserProfileCustomizations.stylesheets` to true in `about:`, then added `chrome/userChrome.css` in the profile dir
I'll save a copy of this css file in the week 10 submission

### 5.
Created a selenium script to log into my school's portal automatically as their remember user button does not work and their system regurlarily fails to authenticate me. Hopefully I'll be able to click a shortcut and autologin. 

Succesfully resolved logging into my school's horrific portal. Just replace your username, password, and web profile path in the python script and package with pyinstaller:
```pyinstaller --onedir --windowed --collect-all selenium yourscript.py```

make sure to install deps first: `pip install selenium pyinstaller` I'm using firefox but you can use a chromium based driver too.
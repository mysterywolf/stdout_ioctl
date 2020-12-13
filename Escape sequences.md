# Escape sequences (ANSI Esc code)

[Xterm Control Sequences (xfree86.org)](https://www.xfree86.org/current/ctlseqs.html)

> *P s* = 1 → De-iconify window.*
> P s* = 2 → Iconify window.*
> **P s* = 3 ; *x ; y* → Move window to [x, y].***
> ~~P s* = 4 ; *height ; width* → Resize the *xterm* window to height and width in pixels.*~~
> P s* = 5 → Raise the *xterm* window to the front of the stacking order.*
> P s* = 6 → Lower the *xterm* window to the bottom of the stacking order.*
> P s* = 7 → Refresh the *xterm* window.*
> **P s* = 8 ; *height ; width* → Resize the text area to [height;width] in characters.***
> **P s* = 9 ; 0 → Restore maximized window.***
> **P s* = 9 ; 1 → Maximize window (i.e., resize to screen size).***
> P s* = 1 1 → Report *xterm* window state. If the *xterm* window is open (non-iconified), it returns CSI 1 t . If the *xterm* window is iconified, it returns CSI 2 t .*
> P s* = 1 3 → Report *xterm* window position as CSI 3 ; *x*; *y*t*
> P s* = 1 4 → Report *xterm* window in pixels as CSI 4 ; *height* ; *width* t*
> **P s* = 1 8 → Report the size of the text area in characters as CSI 8 ; *height* ; *width* t***
> ~~P s* = 1 9 → Report the size of the screen in characters as CSI 9 ; *height* ; *width* t*~~
> P s* = 2 0 → Report *xterm* window’s icon label as OSC L *label* ST*
> P s* = 2 1 → Report *xterm* window’s title as OSC l *title* ST



## 2. DSR – Device Status Report

### 2.1 获取当前指针位置

发送

```
\033[6n
```

终端会立刻返回

```
\033[3;33R\033[1;1R
```

即当前输入指针位置为(1,1)



### 2.2 获取当前终端窗口位于桌面的位置

发送

```
\033[13t
```

终端会立刻返回

```
\033[3;42;328t
```

42为x 328为y



### 2.3 获取当前终端窗口的text area in characters

发送

```
\033[18t
```

终端会立刻返回

```
\033[8;1;15t
```

表示目前终端窗口可以输入15个字符 只能有1行，长15 宽1



## 3. 设置窗口属性



### 3.1 设置终端大小

```
\033[8;100;100t
```

此时终端窗口会变成100*100字符大小



### 3.2 设置终端位置

```
\033[3;100;100t
```

此时终端窗口会落在屏幕(100,100)像素点处（左上角）



### 3.3 终端窗口最大化

设置窗口最大化

```
\033[9;1t
```

恢复窗口到之前的大小

```
\033[9;0t
```


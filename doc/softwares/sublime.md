[TOC]
# markdown
**sublime 3不支持实时预览，需要浏览器来看效果****
preferences->Key Bindings User 输入：
[
    { "keys": ["ctrl+r"], "command": "markdown_preview", "args":   {"target": "browser", "parser":"markdown"} }
]
Ctrl + r 快速打开浏览器

- markdown实时预览


# sublime
- packet control无法安装包，ctrl+`看到控制台提示如下错误：
```
Package Control: Attempting to use Urllib downloader due to WinINet error: Error downloading channel. Connection refused (errno 12029) during HTTP write phase of downloading https://packagecontrol.io/channel_v3.json.
Package Control: Error downloading channel. URL error [WinError 10051] 向一个无法连接的网络尝试了一个套接字操作。 downloading https://packagecontrol.io/channel_v3.json.
```
    因为网络原因，被墙了，无法访问这个URL，VPN开着浏览器可以访问这个URL。一种解决办法是给sublime设置代理，不知道怎么设置。使用如下方法来处理：
    首先VPN访问这个地址将https://packagecontrol.io/channel_v3.json下载到本地，然后prefences->package settings->package control->Settings User里添加
    ```
        "channels": [
        "D:\\IDE\\Sublime Text 3\\channel_v3.json"
    ]
    ```
    sublime会用这个里的设置覆盖默认里的配置，然后就可以继续使用package control了

**markdown 无法使用**
Traceback (most recent call last):
  File "D:\IDE\Sublime Text 3\sublime_plugin.py", line 812, in run_
    return self.run(edit, **args)
  File "MarkdownPreview in C:\Users\Administrator\AppData\Roaming\Sublime Text 3\Installed Packages\Markdown Preview.sublime-package", line 1126, in run
  File "MarkdownPreview in C:\Users\Administrator\AppData\Roaming\Sublime Text 3\Installed Packages\Markdown Preview.sublime-package", line 784, in run
  File "MarkdownPreview in C:\Users\Administrator\AppData\Roaming\Sublime Text 3\Installed Packages\Markdown Preview.sublime-package", line 423, in get_stylesheet
  File "MarkdownPreview in C:\Users\Administrator\AppData\Roaming\Sublime Text 3\Installed Packages\Markdown Preview.sublime-package", line 394, in get_default_css
  File "MarkdownPreview in C:\Users\Administrator\AppData\Roaming\Sublime Text 3\Installed Packages\Markdown Preview.sublime-package", line 385, in isurl
  File "./python3.3/re.py", line 156, in match
TypeError: expected string or buffer


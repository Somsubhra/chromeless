Lils
====

The Lils Runtime Environment runs packaged HTML5 apps(.lx packages) on the desktop(Linux, Windows, OSX, etc.). With the runtime environment installed, you can simply run the app by running the .lx file.

###.lx app packages
.lx app packages are simply HTML5/CSS3/Javascript applications packaged using Zip format, but having .lx extension. Each app package has an app.json file which specifies the application properties.

### Porting existing HTML5 applications
Porting existing HTML5 applications is very simple involving following steps:
* Add an app.json file with application properties to the directory containing your application files.
* Name the entry point of the application as index.html.
* Zip the application files, index.html and app.json into an archive and rename it with .lx extension.
* Your App is ready to run :)

### app.json structure
```json
{
  "version": "1.0.0",
  "name": "AppName",
  "description": "Your App description",
  
  "author": {
    "name": "Somsubhra",
    "email": "mail@somsubhra.com"
  },
  
  "window": {
    "maxWidth": 400,
    "maxHeight": 500,
    "minWidth": 200,
    "minHeight": 250,
    "fixedWidth": 450,
    "fixedHeight": 450,
    "maximized": false,
    "hideTitleBar": true    
  }
}
```

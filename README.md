Lils
====

The Lils Runtime Environment runs packaged HTML5 apps(.lx packages) on the desktop(Linux, Windows, OSX, etc.). With the runtime environment installed, you can run the app by simply running the .lx file.

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
### Lils Runtime Build Instructions

##### Dependencies
* Qt5

##### Getting the source code
* Clone the repository.
```sh
git clone https://github.com/Somsubhra/Lils.git
```
##### Build Steps
* Create a build directory.
```sh
mkdir build
cd build
```

* Configure project.
```sh
qmake /path/to/Lils.pro
```

* Compile.
```sh
make -j5
```

* Simpler Way: Open Lils.pro using QtCreator and Build from IDE itself.

##### Run Steps
###### Command Line
* Run without arguments to open the Control Panel.
```sh
/path/to/app
```

* Run with app package name as argument to run the app.
```sh
/path/to/app myapp.lx
```

###### From the GUI
* Running app executable will open control panel.
* Running a .lx app package will run the app.

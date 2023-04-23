Calculator for the second IVS project for academic year 2022/2023
===

A simple graphical calculator. <br>
The main focus of our IVS project for the academic year 2022/2023 at BUT FIT.

Installing
---
#### Installing from source
```sh
git clone --recursive https://github.com/Zeftax/ivs2-calculator
cd ivs2-calculator/src && sudo make calc-install
```
The program will be installed to the `/usr/bin` directory. <br>
If you wish to install it elsewhere, set `-DCMAKE_INSTALL_PREFIX:PATH` to your 
desired destination.
##### Uninstalling:
```sh
sudo make calc-uninstall
```

#### Using a deb package
If you're on a debian based system, you can use a .deb package provided in 
releases. <br>
Right click the package and install it using the Ubuntu Software Centre or via
terminal:
```sh
sudo dpkg -i <package_name.deb>
```

##### Uninstalling:
You can uninstall the calculator in the Ubuntu Software Centre or via terminal:
```sh
sudo dpkg -r ivs-ratulator
```

Subprojects
---
This repository currently uses 2 git submodules which are also part of this project:
- [math library](https://github.com/Zeftax/ivs2-mathlib)
- [profiler](https://github.com/Zeftax/ivs2-profiler)

#### Updating submodules
**Note: only applies to the installation from source method** <br>
<br>
In the project root directory:
```sh
git pull && git submodule update --recursive
```
In the respective submodule directory (e.g. `src/extern/ivs2-mathlib`):
```sh
git pull
```

Additional targets
---
Run math library tests:
```sh
make test
```

Compile profiler:
```sh
make profile
```
Executable will be located in `_bin` directory.

Generate documentation:
```sh
make doc
```


License
---
Copyright (C) <2023>  <xborov08, xkrejc84, xlozrt00, xmitre07>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.

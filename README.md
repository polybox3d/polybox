polybox
=======

Contact :
---------
<b>Mail :</b> Florian Boudinet   <florian.boudinet@gmail.com>

<b>IRC :</b> RepRap IRC <irc.freenode.net> #reprap / #reprap-fr


Requirements
============
You need some package to compile and use Polybox Software.
This is a non-exhaustive list :
* C++ compiler... 
* Qt5.0 or superior 
* OpenCV2
* PCL (with FLANN)
* Boost

apt-get install gcc g++ build-essential
apt-get install qt5-default qtmultimedia5-dev libqt5-*
apt-get install qtcreator

Usage
=====

First, you need to clone (or download) this repository.
Then, the project need to update submodule from external repository.
Run : 
```
 git submodule init 
 git submodule update
```
The first command init git submodule, the second update and getfiles from external repo.

To pull current and external repository updatge use : 

```
 git pull --recurse-submodules
```

Mettre à jours les sous modules.
1/ Se placer dans le repertoire concerné
```
cd externals/Polyplexer
```
2/ Changer la branche et recuperer les commit
```
git checkout master
```
Compilation
=====

You can compile PolyboxSoftware using command line or QtCreator
Be careful, software needs to compiled with qmake5. 
Path: /usr/lib/i386-linux-gnu/qt5/bin/qmake

1/ using command line
```
cd ~/polybox/src
qmake5
make
```
2/ using QtCreator



License
=======

This software is under MIT license.

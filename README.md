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


M-Code
=======
Link to M-Code :
https://docs.google.com/spreadsheet/ccc?key=0AnG5RystvX2ZdFc4Y1RpcW5FWmlhTnFtcm92Y2d6NGc&usp=sharing


Translation
===========

Qt provides a powerfull process to translate software's string.

Translation files are stored in /polybox/i18n/ as TS file.

1/ Step 1 : create/update TS file.
When you want to start a translation process, you first need to extract all the string.
In a terminal, go inside the source repertory, and execute lupdate command : 
```
lupdate polybox.pro
```
2/ Translate the file
Then, you have ot translate TR file using QLinguist



License
=======

This software is under MIT license.

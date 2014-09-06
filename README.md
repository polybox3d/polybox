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
apt-get install qtcreator qttools5-dev-tools

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
You can download all Qt5 tools by running apt
```
sudo apt-get install qttools5-dev-tools
```

Translation files are stored in /polybox/i18n/ as TS file.
The process is in 3 step. Updtae/create translate file. Translate the file/string. Then publish the translated file.
You can use QtCreator to update/publish TR files. (Tools > External > Linguist)

1/ Create/update TS file.

When you want to start a translation process, you first need to extract all the string.
In a terminal, go inside the source repertory, and execute lupdate command : 
```
lupdate polybox.pro
```
2/ Translate the file

Then, you have ot translate TR file using QLinguist

3/ Convert TR file

Finally, we need to convert the translated TR file into an QM file. QM file will be included at the next software compilation.

```
lrelease polybox.pro
```


References:
* http://qt-project.org/doc/qt-5/linguist-translators.html
* http://qt-project.org/doc/qt-5/internationalization.html
* http://qt-project.org/doc/qt-5/qtlinguist-index.html



License
=======

This software is under MIT license.

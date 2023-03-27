# DeleteLater

Cet exemple présente l'utilisation du Slot `QObject::deleteLater` afin de programmer la destruction d'un objet suite à l'émission d'un signal

## Utilisation

Modifiez la valeur de la macro `TP` dans le fichier `main.cpp`. Les valeurs possibles vont de 1 à 3.

## Analyse

Un objet témoin est instancié et il est transmis comme référence à un autre objet qui le stocke et qui y accèdera plus tard. Or l'objet témoin est supprimé et lorsque l'autre objet tente d'y accéder, il peut y avoir des problèmes, sauf si la destruction de l'objet témoin est réalisée au bon moment, grâce à une inversion de contrôle.

### TP n°1

Dans cet exemple, le témoin est détruit avec l'opérateur `delete` juste après l'appel de la fonction qui est censée l'utiliser. Cela provoque un crash.

### TP n°2

Dans cet exemple, ce n'est plus le contrôleur qui détruit l'objet témoin, mais le récepteur qui se détruit lui-même, et lorsque le programme se termine, le contrôleur est détruit et comme il est le parent de l'objet témoin, il le détruit.

Cette approche est convenable mais pas optimale.

### TP n°3

Dans cet exemple, le contrôleur transmet le témoin au récepteur qui l'utilise. Lorsque le récepteur est détruit, il envoit un signal `destroyed` qui est capté par le contrôleur. Au préalable, le signal `destroyed` a été connecté au Slot `deleteLater` du témoin pour synchroniser la suppression des objets. C'est une inversion de contrôle.

Cet exemple est également utilisé dans le cas de la programmation des threads.
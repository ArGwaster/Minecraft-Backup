# Script de Sauvegarde Minecraft

Ce dépôt contient un ensemble de scripts en C++ pour sauvegarder et transférer des fichiers de serveur Minecraft. Les scripts automatisent le processus de création de sauvegardes et de déplacement vers un serveur distant.

## Fonctionnalités

-   Sauvegardes périodiques des fichiers du serveur Minecraft.
-   Transfert des sauvegardes vers un serveur distant.
-   Génération de fichiers de log pour suivre le processus de sauvegarde et de transfert.

## Prérequis

-   Compilateur C++ (testé avec g++).
-   Clé SSH pour accéder au serveur distant.

## Scripts

### `backup.cpp`

Ce script effectue les tâches suivantes :

1.  Sauvegarde périodique des fichiers du serveur Minecraft dans un répertoire local.
2.  Génère des fichiers de log pour suivre le processus de sauvegarde.

#### Utilisation

1. Editer le script avec vos informations  
2. Compiler le script : `g++ backup.cpp -o backup`
3. Exécuter le script : `./backup`

### `restore.cpp`

Ce script transfère les fichiers sauvegardés vers un serveur distant.

#### Utilisation

1. Editer le script avec vos informations    
2. Compiler le script : `g++ push.cpp -o restore`
3. Exécuter le script : `./restore`

## Fichiers de log

Le script `backup.cpp` génère des fichiers de logs. Les fichiers logs sont nommés `backup.log`.

## Licence

Ce projet est sous licence MIT - voir le fichier [LICENSE](https://www.blackbox.ai/chat/LICENSE) pour plus de détails.

## Avertissement

Ce projet n'est pas un projet officiel de Minecraft et n'est pas affilié à Mojang Studios ou à Minecraft. Il est fourni tel quel, sans aucune garantie. Utilisez à vos propres risques.
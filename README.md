# Création et initialisation d'un conteneur Docker

## Initialisation

### 1. Créer le Dockerfile

Créez un fichier nommé **Dockerfile** dans le répertoire du projet avec le contenu suivant :

```dockerfile
# Utilise une image de base officielle avec GCC
FROM gcc:14.1.0

# Installe ncurses et d'autres bibliothèques nécessaires
RUN apt-get update && apt-get install -y \
    libncurses5-dev \
    libncursesw5-dev

# Crée un répertoire de travail
WORKDIR /usr/src/convertisseur

# Copie les fichiers sources dans le conteneur
COPY . .

# Compile le programme
RUN gcc -o convertisseur convertisseur.c -lncurses -lm

# Commande par défaut pour exécuter le programme
CMD ["./convertisseur"]
```

### 2. Fichiers source

Vérifier que le fichier source principal, par exemple convertisseur.c, est dans le même répertoire que votre Dockerfile. Voici un exemple de convertisseur.c :

```markdown
.
├── convertisseur.c
├── Dockerfile
└── README.md
```

### 3. Construire et exécuter le conteneur Docker

Ouvrez un terminal et naviguez jusqu'au répertoire contenant votre Dockerfile et main.c.

Construisez l'image Docker avec la commande suivante :

```sh
docker build -t convertisseur-image .
```

Exécutez le conteneur Docker avec la commande suivante :

```sh
    docker run --rm -it convertisseur-image
```

Cette commande compile le programme à l'intérieur du conteneur Docker et exécute le binaire généré. 
La sortie du programme sera affichée dans le terminal.
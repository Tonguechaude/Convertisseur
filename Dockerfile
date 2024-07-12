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

# Commande pour exécuter le programme
CMD ["./convertisseur"]

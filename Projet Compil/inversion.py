from PIL import Image
import numpy as np

# On charge l'image et on la transforme en tableau contenant les couleurs
image_entrée = Image.open("img1.jpg")
image = np.asarray(image_entrée)

# Partie à compléter
image_sortie = 255 - image

# On sauvegarde les images pour pouvoir les afficher
Image.fromarray(image).save("image_entree.png")
Image.fromarray(image_sortie).save("image_sortie.png")

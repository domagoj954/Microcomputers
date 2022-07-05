from PIL import Image

img = Image.open('sign.PNG')
i = img.convert('RGB')
i.save('sign.PNG')

#i=img.convert("P", palette=Image.Palette.ADAPTIVE, colors=24)
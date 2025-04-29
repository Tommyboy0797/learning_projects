from tkinter import Tk, filedialog
from PIL import Image

def open_and_overlay():
    basepath = filedialog.askopenfilename(title="open base picture")
    base = Image.open(basepath).convert("RGBA")

    overlay1_path = filedialog.askopenfilename(title="open top left overlay")
    overlay2_path = filedialog.askopenfilename(title="open top right overlay")
    overlay1 = Image.open(overlay1_path).convert("RGBA")
    overlay2 = Image.open(overlay2_path).convert("RGBA")

    base.paste(overlay1, (0,0), overlay1)
    base.paste(overlay2, (base.width - overlay2.width, 0), overlay2)

    base.save(f"converted.png")

open_and_overlay()

from tkinter import Tk, filedialog
from PIL import Image
import os

def open_and_overlay_bulk():
    Tk().withdraw()

    base_paths = filedialog.askopenfilenames(title="Select base pictures")

    if not base_paths:
        print("No base images selected.")
        return

    overlay1_path = filedialog.askopenfilename(title="Open top left overlay")
    overlay2_path = filedialog.askopenfilename(title="Open top right overlay")

    if not overlay1_path or not overlay2_path:
        print("Overlay selection cancelled.")
        return

    overlay1 = Image.open(overlay1_path).convert("RGBA")
    overlay2 = Image.open(overlay2_path).convert("RGBA")

    scale = 0.15
    overlay1 = overlay1.resize((int(overlay1.width * scale), int(overlay1.height * scale)))
    overlay2 = overlay2.resize((int(overlay2.width * scale), int(overlay2.height * scale)))

    for base_path in base_paths:
        base = Image.open(base_path).convert("RGBA")
        base_copy = base.copy()

        base_copy.paste(overlay1, (0, 0), overlay1)
        base_copy.paste(overlay2, (base.width - overlay2.width, 0), overlay2)

        filename = os.path.basename(base_path)
        output_path = os.path.join(os.path.dirname(base_path), f"converted_{filename}")
        base_copy.save(output_path)
        print(f"Saved: {output_path}")

open_and_overlay_bulk()

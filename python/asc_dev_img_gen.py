from PIL import Image
from tkinter import filedialog, Tk
import os

# Hide main tkinter window
root = Tk()
root.withdraw()

# Get Downloads folder path
downloads_path = os.path.join(os.path.expanduser("~"), "Downloads")

# Select multiple base images
base_paths = filedialog.askopenfilenames(title="Select base images", filetypes=[("Images", "*.png;*.jpg;*.jpeg")])
if not base_paths:
    print("No base images selected.")
    exit()

# Select single overlay image (banner/watermark)
overlay_path = filedialog.askopenfilename(title="Select overlay image", filetypes=[("Images", "*.png;*.jpg;*.jpeg")])
if not overlay_path:
    print("No overlay image selected.")
    exit()

# Open overlay and convert to RGBA
overlay_img = Image.open(overlay_path).convert("RGBA")

# Process each base image
for base_path in base_paths:
    base_img = Image.open(base_path).convert("RGBA")
    
    # Resize overlay to match base
    resized_overlay = overlay_img.resize((base_img.width, base_img.height))

    # Apply overlay
    result = Image.alpha_composite(base_img, resized_overlay)

    # Build output path
    base_name = os.path.basename(base_path)
    name, ext = os.path.splitext(base_name)
    output_filename = f"{name}_watermarked.png"
    output_path = os.path.join(downloads_path, output_filename)

    # Save result
    result.save(output_path)

    print(f"Saved: {output_path}")

print("All images processed and saved to Downloads.")

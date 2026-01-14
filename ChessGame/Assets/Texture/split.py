from PIL import Image
import os
import zipfile

image_path = 'r.png'
img = Image.open(image_path)

# Calculate individual icon dimensions
icon_width = img.width // 12  # 12 columns
icon_height = img.height // 8  # 8 rows

# Prepare output directory
# zip
# output_dir = '/mnt/data/chess_pieces'
# not zip
output_dir = 'chess_pieces'
os.makedirs(output_dir, exist_ok=True)

# Loop to crop individual icons
pieces = []

marginY = 0
for row in range(8):  # 8 rows
    sizeXY = 800
    marginX = 30
    for col in range(12):  # 12 columns
        
        left = (sizeXY + 40) * col
        upper = (sizeXY + 280) * row
        right = left + sizeXY
        lower = upper + sizeXY
        cropped = img.crop((left, upper, right, lower))
        
        # Save each icon with transparency
        output_path = os.path.join(output_dir, f'piece_{row}_{col}.png')
        cropped.save(output_path, format="PNG")
        pieces.append(output_path)

pieces[:5]  # Display the first few paths to confirm execution

zip_path = 'chess_pieces.zip'
with zipfile.ZipFile(zip_path, 'w') as zipf:
    for piece_path in pieces:
        zipf.write(piece_path, os.path.basename(piece_path))

# zip_path

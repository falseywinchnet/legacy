#!/usr/bin/env python3
"""Render the application's geometric coastal-profile icon (Pillow, development only)."""
from pathlib import Path
from PIL import Image, ImageDraw
import math
root = Path(__file__).resolve().parents[1] / 'resources'
image = Image.new('RGBA', (1024,1024))
draw = ImageDraw.Draw(image)
draw.rounded_rectangle((24,24,1000,1000), radius=210, fill='#153b53')
draw.line([(165,220),(165,797),(861,797)], fill='#7698a7', width=12, joint='curve')
shore = [(180,726),(320,690),(450,615),(536,486),(633,389),(683,451),(846,479)]
draw.polygon(shore+[(846,780),(180,780)], fill='#ccad7e')
draw.line(shore, fill='#f6dec0', width=18, joint='curve')
wave = [(x,round(550-45*math.sin((x-165)*math.pi/180))) for x in range(180,849)]
draw.line(wave,fill='#53d8cb',width=24,joint='curve')
draw.ellipse((617,373,649,405),fill='#fff5de')
image.save(root/'coastal.png')
image.save(root/'coastal.ico',sizes=[(16,16),(24,24),(32,32),(48,48),(64,64),(128,128),(256,256)])
image.save(root/'coastal.icns')

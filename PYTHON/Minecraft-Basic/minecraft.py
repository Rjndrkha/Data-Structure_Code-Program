from ursina import *
from ursina.prefabs.first_person_controller import FirstPersonController
app = Ursina()
# grass_texture = load_texture('grass_block.png')
player = FirstPersonController()
Sky()
boxes = []
for i in range(20):
  for j in range(20):
    box = Button(color=color.white, model='cube', position=(j,0,i),
          texture='Minecraft-Grass-Blur.png', parent=scene, origin_y=0.5)
    boxes.append(box)

def input(key):
  for box in boxes:
    if box.hovered:
      if key == 'left mouse down':
        new = Button(color=color.white, model='cube', position=box.position + mouse.normal,
                    texture='Minecraft-Grass-Blur.png', parent=scene, origin_y=0.5)
        boxes.append(new)
      if key == 'right mouse down':
        boxes.remove(box)
        destroy(box)

# def input(key):
#   if key == 'q' or 'escape':
#     quit()

app.run()

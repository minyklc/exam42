from config import TILE_W, TILE_H

def iso_coords(x, y, screen_width):
    screen_x = (x - y) * TILE_W // 2 + screen_width // 2
    screen_y = (x + y) * TILE_H // 2 + 50
    return screen_x, screen_y

def screen_to_grid(mx, my, screen_width):
    mx -= screen_width // 2
    my -= 50

    gx = mx / (TILE_W / 2)
    gy = my / (TILE_H / 2)

    x = round((gy + gx) / 2)
    y = round((gy - gx) / 2)

    return int(x), int(y)
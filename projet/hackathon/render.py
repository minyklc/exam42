import pygame
from config import MAP_W, MAP_H
from isometric import iso_coords
import avatars

def draw_tile(x, y, color, surface, screen_width):
    px, py = iso_coords(x, y, screen_width)
    points = [
        (px, py),
        (px + 32, py + 16),
        (px, py + 32),
        (px - 32, py + 16),
    ]
    pygame.draw.polygon(surface, color, points)
    pygame.draw.polygon(surface, (60, 60, 60), points, 2)

def draw_character(char, surface, screen_width):
    px, py = iso_coords(char["x"], char["y"], screen_width)
    img = avatars.get_avatar(char["avatar"])
    if img:
        rect = img.get_rect(center=(px, py))
        surface.blit(img, rect)

def draw_map(surface, map_data, screen_width, biome_colors):
    surface.fill((30, 30, 30))
    color = biome_colors[map_data["biome"]]

    for x in range(MAP_W):
        for y in range(MAP_H):
            draw_tile(x, y, color, surface, screen_width)

    for char in map_data["characters"]:
        draw_character(char, surface, screen_width)
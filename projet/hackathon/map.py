import pygame
import avatars
from config import *
from isometric import screen_to_grid
from render import draw_map
from world import create_map, add_character_to_map

pygame.init()

screen = pygame.display.set_mode((1280, 720))
clock = pygame.time.Clock()

avatars.load_avatars()

maps = [
    create_map("plains"),
    create_map("forest"),
    create_map("desert"),
    create_map("snow"),
]

current_map_index = 0
is_sliding = False
slide_offset = 0
slide_direction = 0

map_surface = pygame.Surface(screen.get_size())

running = True
while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

        if event.type == pygame.MOUSEBUTTONDOWN and event.button == 1 and not is_sliding:
            x, y = screen_to_grid(*pygame.mouse.get_pos(), screen.get_width())
            add_character_to_map(maps[current_map_index], x, y)

        if event.type == pygame.KEYDOWN and not is_sliding:
            if event.key == pygame.K_UP and current_map_index < len(maps) - 1:
                slide_direction = 1
                is_sliding = True
            elif event.key == pygame.K_DOWN and current_map_index > 0:
                slide_direction = -1
                is_sliding = True

    screen.fill((0, 0, 0))

    if is_sliding:
        slide_offset += 40 * slide_direction
        draw_map(map_surface, maps[current_map_index], screen.get_width(), BIOMES)
        screen.blit(map_surface, (0, slide_offset))

        next_index = current_map_index + slide_direction
        draw_map(map_surface, maps[next_index], screen.get_width(), BIOMES)
        screen.blit(map_surface, (0, slide_offset - slide_direction * screen.get_height()))

        if abs(slide_offset) >= screen.get_height():
            current_map_index = next_index
            slide_offset = 0
            is_sliding = False
    else:
        draw_map(screen, maps[current_map_index], screen.get_width(), BIOMES)

    pygame.display.flip()
    clock.tick(60)

pygame.quit()
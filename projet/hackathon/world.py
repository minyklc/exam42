from config import MAP_W, MAP_H, BIOME_CHARACTERS

def create_map(biome):
    return {
        "biome": biome,
        "tiles": [[0]*MAP_H for _ in range(MAP_W)],
        "characters": []
    }

def add_character_to_map(map_data, x, y):
    biome = map_data["biome"]
    allowed = BIOME_CHARACTERS.get(biome, [])

    if not allowed:
        return False

    map_data["characters"].append({
        "x": x,
        "y": y,
        "avatar": allowed[0]
    })
    return True
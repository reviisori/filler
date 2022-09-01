# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    main.py                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/25 14:26:19 by altikka           #+#    #+#              #
#    Updated: 2022/09/01 16:20:31 by altikka          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import pygame
import sys


pygame.init()

###main window and title:
pygame.display.set_caption("Filler Visualiser")
resolution = 800
window = pygame.display.set_mode((resolution, resolution))
bg_main= pygame.Surface((resolution, resolution))
bg_main.fill(pygame.Color("#becb11"))
bg_play = pygame.Surface((resolution, resolution))
bg_play.fill(pygame.Color("#11cb7b"))

###load & scale logo & buttons:
logo_img = pygame.image.load("./resources/filler_logo.png").convert_alpha()
logo_img = pygame.transform.scale(logo_img, (600, 160))
start_img = pygame.image.load("./resources/button_start.png").convert_alpha()
start_img = pygame.transform.scale(start_img, (210, 90))
start_d_img = pygame.image.load("./resources/button_start_down.png").convert_alpha()
start_d_img = pygame.transform.scale(start_d_img, (210, 90))

###button class:
class button():
    def __init__(self, x, y, image):
        self.image = image
        self.rect = self.image.get_rect()
        self.rect.topleft = (x, y)
        self.clicked = False

    def draw(self, surface):
        mouse_action = False
        mouse_pos = pygame.mouse.get_pos()
        if self.rect.collidepoint(mouse_pos):
            if pygame.mouse.get_pressed()[0] == 1 and self.clicked == False:
                self.clicked = True
                mouse_action = True
            if pygame.mouse.get_pressed()[0] == 0:
                self.clicked = False
        surface.blit(self.image, (self.rect.x,  self.rect.y))
        return mouse_action

###button variables:
start_button = button(295, 525, start_img)
start_button_d = button(295, 525, start_d_img)

###function to load & scale map resources accordingly:
def load_map_resources(sqr_side):
    empty_img = pygame.image.load("./resources/sqr_empty.png").convert_alpha()
    empty_img = pygame.transform.scale(empty_img, (sqr_side, sqr_side))
    o_img = pygame.image.load("./resources/sqr_o.png").convert_alpha()
    o_img = pygame.transform.scale(o_img, (sqr_side, sqr_side))
    x_img = pygame.image.load("./resources/sqr_x.png").convert_alpha()
    x_img = pygame.transform.scale(x_img, (sqr_side, sqr_side))
    return empty_img, o_img, x_img

###function to init map data:
def init_map_data(dim, res):
    if dim == 15:
        sqr_side = 40
        x = (resolution - sqr_side * dim) / 2
        y = (resolution - sqr_side * 17) / 2
    elif dim == 24:
        sqr_side = 19
        x = (resolution - sqr_side * dim) / 2
        y = (resolution - sqr_side * 40) / 2
    else:
        sqr_side = 6
        x = (resolution - sqr_side * dim) / 2
        y = (resolution - sqr_side * 99) / 2
    return x, y, sqr_side 

###function to quickly skip x ammount of line in stdin:
def return_next_line(x):
    for _ in range(x):
        sys.stdin.readline()
    str = sys.stdin.readline()
    return str

def pause_game():
    paused = True
    while paused:
        for event in pygame.event.get():
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_SPACE:
                    print(">")
                    paused = False

###game loop:
def play():
    is_playing = True
    init_data = True
    paused = True

    ###I: get player data
    if init_data:
        p1 = return_next_line(5)
        p2 = return_next_line(1)
        #print(p1)#needs better splitting and grebbing
        #print(p2)#for future display

        ###II: get map data
        plateau = return_next_line(1)
        map_size = plateau.rstrip(":\n").split(" ")
        map_x = int(map_size[1])
        map_y = int(map_size[2])
        init_data = False
        #print(plateau)
        #print(map_x, map_y)

    while is_playing:
        window.blit(bg_play, (0, 0))
        for event in pygame.event.get():
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_SPACE and paused == False:
                    print("||")
                    pause_game()
                if event.key == pygame.K_ESCAPE:
                    print("Exiting the game...")
                    is_playing = False
            if event.type == pygame.QUIT:
                print("Exiting the game...")
                is_playing = False

        ###V: exit the game
        s = sys.stdin.readline()#has '== X fin: ...' at the end
        fin = s.split(" ")
        if "fin" in fin[2]:
            print("FIN")
            is_playing = False
            pygame.time.wait(2000)
            return

        ###III: draw the map
        x_ofs, y_ofs, sqr_side, = init_map_data(map_x, resolution)
        empty_img, o_img, x_img = load_map_resources(sqr_side)
        y_reset = y_ofs
        x = 0
        while x < map_x:
            s = sys.stdin.readline()
            y = 4
            while y < map_y + 4:
                if s[y] == 'o' or s[y] == 'O':
                    window.blit(o_img, (y_ofs, x_ofs))
                elif s[y] == 'x' or s[y] == 'X':
                    window.blit(x_img, (y_ofs, x_ofs))
                else:
                    window.blit(empty_img, (y_ofs, x_ofs))
                y_ofs = y_ofs + sqr_side
                y += 1
            x_ofs = x_ofs + sqr_side
            y_ofs = y_reset
            x += 1

        ###IV: get piece data SKIPPED RN
        piece = return_next_line(0)
        piece_size = piece.rstrip(":\n").split(" ")
        piece_x = int(piece_size[1])
        piece_y = int(piece_size[2])
        s = return_next_line(piece_x + 1)#THE SKIP

        ##react if one of the players can't play anymore
        faint = s.rstrip(":\n").split(" ")
        if "Piece" in faint[0]:
            s = return_next_line(int(faint[1]) + 1)
        #print(piece)
        #print(piece_x, piece_y)

        pygame.display.update()
        if paused:
            print("||")
            pause_game()
            paused = False
        pygame.time.wait(30)#speed of the game

###main menu:
is_running = True
while is_running:
    window.blit(bg_main, (0, 0))
    window.blit(logo_img, (100, 340))
    
    if start_button.draw(window):
        start_button_d.draw(window)
        pygame.display.update()
        pygame.time.wait(240)
        print("PLAY")
        play()

    for event in pygame.event.get():
        if event.type == pygame.KEYDOWN:
            if event.key == pygame.K_RETURN:
                start_button_d.draw(window)
                pygame.display.update()
                pygame.time.wait(240)
                print("PLAY")
                play()
            if event.key == pygame.K_ESCAPE:
                print("Quitting...")
                is_running = False
        if event.type == pygame.QUIT:
            print("Quitting...")
            is_running = False

    pygame.display.update()

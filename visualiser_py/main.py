# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    main.py                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/25 14:26:19 by altikka           #+#    #+#              #
#    Updated: 2022/08/30 17:07:15 by altikka          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import pygame
import sys


pygame.init()

###main window and title:
pygame.display.set_caption('Filler Visualiser')
window = pygame.display.set_mode((800, 800))
background = pygame.Surface((800, 800))
background.fill(pygame.Color('#becb11'))

bg_test = pygame.Surface((800, 800))
bg_test.fill(pygame.Color('#11cb7b'))

###load & scale images:
logo_img = pygame.image.load("./resources/filler_logo.png").convert_alpha()
logo_img = pygame.transform.scale(logo_img, (600, 160))
start_img = pygame.image.load("./resources/button_start.png").convert_alpha()
start_img = pygame.transform.scale(start_img, (210, 90))
start_d_img = pygame.image.load("./resources/button_start_down.png").convert_alpha()
start_d_img = pygame.transform.scale(start_d_img, (210, 90))
empty_img = pygame.image.load("./resources/sqr_empty.png").convert_alpha()
empty_img = pygame.transform.scale(empty_img, (43, 43))# 44x44 for map00, 15x15 for map01 and 5x5 for map02


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

##################################
#                                #
# I: get player data             #
# II: get board data             #
# III: draw the board            #
# IV: get piece data             #
# V: update the board and pieces #
#                                #
##################################

def return_next_line(x):
    for _ in range(x):
        sys.stdin.readline()
    str = sys.stdin.readline()
    return str

###game loop:
init_data = True
def play():
    is_playing = True
    global init_data

    ###I: player data
    if init_data:
        p1 = return_next_line(5)
        p2 = return_next_line(1)
        print(p1)#needs better splitting and grebbing
        print(p2)#^

        ###II: map data
        plateau = return_next_line(1)
        print(plateau)
        map_size = plateau.rstrip(":\n").split(" ")
        map_x = int(map_size[1])
        map_y = int(map_size[2])
        print(map_x, map_y)
        init_data = False
    while is_playing:
        window.blit(bg_test, (0, 0))
        for event in pygame.event.get():
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_ESCAPE:
                    print("Exiting the game...")
                    is_playing = False
            if event.type == pygame.QUIT:
                print("Exiting the game...")
                is_playing = False

        ###III: drawing the map
        sqr_side = 43
        x_ofs = 10
        y_ofs = 25
        s = sys.stdin.readline()
        x = 0
        while x < map_x:
            s = sys.stdin.readline()
            y = 4
            while y < map_y + 4:
                window.blit(empty_img, (y_ofs, x_ofs))
                y_ofs = y_ofs + sqr_side
                #print(s[y], end=" ")#test
                y += 1
            x_ofs = x_ofs + sqr_side
            y_ofs = 25
            #print("\n")#test
            x += 1
        pygame.display.update()
        pygame.time.wait(60)

### button variables:
start_button = button(295, 525, start_img)
start_button_d = button(295, 525, start_d_img)

###event loop:
is_running = True
while is_running:
    window.blit(background, (0, 0))
    window.blit(logo_img, (100, 340))
    
    ###draw the actual button:
    if start_button.draw(window):
        start_button_d.draw(window)
        pygame.display.update()
        pygame.time.wait(120)

        ###play the game:
        print("PLAY")
        play()

    for event in pygame.event.get():
        if event.type == pygame.KEYDOWN:
            if event.key == pygame.K_ESCAPE:
                print("Quitting...")
                is_running = False
        if event.type == pygame.QUIT:
            print("Quitting...")
            is_running = False
    pygame.display.update()

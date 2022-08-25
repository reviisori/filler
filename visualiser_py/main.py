# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    main.py                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/25 14:26:19 by altikka           #+#    #+#              #
#    Updated: 2022/08/25 16:28:47 by altikka          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import pygame


pygame.init()

pygame.display.set_caption('Filler Visualiser')
window = pygame.display.set_mode((1000, 1000))

background = pygame.Surface((1000, 1000))
background.fill(pygame.Color('#DAF7A6'))

###load & scale images:
start_img = pygame.image.load("./resources/button_start.png").convert_alpha()
start_img = pygame.transform.scale(start_img, (210, 90))

###button class:
class fv_button():
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

###button variable:
start_button = fv_button(395, 455, start_img)

###game loop:
is_running = True
while is_running:

    window.blit(background, (0, 0))
    
    ###draw the actual button:
    if start_button.draw(window):
        print("PLAY THE GAME ON SCREEN")#continue here

    for event in pygame.event.get():

        ###exit:
        if event.type == pygame.KEYDOWN:
            if event.key == pygame.K_ESCAPE:
                print("Quitting...")
                is_running = False
        if event.type == pygame.QUIT:
            is_running = False
    
    pygame.display.update()

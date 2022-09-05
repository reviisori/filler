# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    main.py                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/25 14:26:19 by altikka           #+#    #+#              #
#    Updated: 2022/09/05 18:32:45 by altikka          ###   ########.fr        #
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

###load & scale images:
logo_img = pygame.image.load("./resources/filler_logo.png").convert_alpha()
logo_img = pygame.transform.scale(logo_img, (600, 160))
start_img = pygame.image.load("./resources/button_start.png").convert_alpha()
start_img = pygame.transform.scale(start_img, (210, 90))
start_d_img = pygame.image.load("./resources/button_start_down.png").convert_alpha()
start_d_img = pygame.transform.scale(start_d_img, (210, 90))
play_img = pygame.image.load("./resources/img_play.png").convert_alpha()
play_img = pygame.transform.scale(play_img, (18, 18))
pause_img = pygame.image.load("./resources/img_pause.png").convert_alpha()
pause_img = pygame.transform.scale(pause_img, (18, 18))
ff_img = pygame.image.load("./resources/img_ff.png").convert_alpha()
ff_img = pygame.transform.scale(ff_img, (18, 18))

game_font = "./resources/font_ps.ttf"

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

###function to pause the game loop
def pause_game():
    paused = True
    while paused:
        for event in pygame.event.get():
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_SPACE:
                    paused = False
                if event.key == pygame.K_ESCAPE:
                    print("Exiting the game...")
                    paused = False
                    return False
            if event.type == pygame.QUIT:
                print("Exiting the game...")
                paused = False
                return False
    return True

###game loop:
def play():
    is_playing = True
    init_data = True
    paused = True
    end = False
    game_speed = 50

    ###I: get player data
    if init_data:
        p1 = return_next_line(5)
        p2 = return_next_line(1)
        p1_name = p1.split("/")
        p2_name = p2.split("/")
        print(p1_name[-1].split(".")[0], "vs.", p2_name[-1].split(".")[0])

        ###II: get map data
        plateau = return_next_line(1)
        map_size = plateau.rstrip(":\n").split(" ")
        map_x = int(map_size[1])
        map_y = int(map_size[2])
        init_data = False
        #print(plateau)
        #print(map_x, map_y)

    while is_playing:
        x_ofs, y_ofs, sqr_side, = init_map_data(map_x, resolution)
        empty_img, o_img, x_img = load_map_resources(sqr_side)
        x_reset = x_ofs
        y_reset = y_ofs

        window.blit(bg_play, (0, 0))

        ###player names & game color:
        p1_font = pygame.font.Font(game_font, 18)
        p1_text = p1_font.render(p1_name[-1].split(".")[0], True, "#000000")
        window.blit(p1_text, (y_reset + 70, x_reset - 50))
        p1_img = pygame.image.load("./resources/sqr_o.png").convert_alpha()
        window.blit(p1_img, (y_reset + 55, x_reset - 44))

        p2_font = pygame.font.Font(game_font, 18)
        p2_text = p2_font.render(p2_name[-1].split(".")[0], True, "#000000")
        #window.blit(p2_text, (resolution / 2 + 50, x_reset - 50))# needs calc
        window.blit(p2_text, (y_reset + 70, x_reset - 25))# needs calc
        p2_img = pygame.image.load("./resources/sqr_x.png").convert_alpha()
        #window.blit(p2_img, (resolution / 2 + 35, x_reset - 44))
        window.blit(p2_img, (y_reset + 55, x_reset - 19))

        ###V: exit the game
        s = sys.stdin.readline()
        if end:
            print("O:", int(score_o))
            print("X:", int(score_x))
            print("FIN")
            pause_game()
            is_playing = False
            return

        ###III: draw the map
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

        ###IV: get piece data SKIPPED FOR NOW
        piece = return_next_line(0)
        piece_size = piece.rstrip(":\n").split(" ")
        piece_x = int(piece_size[1])
        piece_y = int(piece_size[2])
        s = return_next_line(piece_x)#THE SKIP

        ###final scores:
        s = return_next_line(0)#has '== 0 fin: ...' at the end
        fin_o = s.split(" ")
        if "fin" in fin_o[2]:
            score_o = fin_o[3]
            s = sys.stdin.readline()#has '== X fin: ...' at the end
            fin_x = s.split(" ")
            if "fin" in fin_x[2]:
                score_x = fin_x[3]
                len_o = len(score_o)
                len_x = len(score_x)
                score_ofs = max(len_o, len_x) - 1
                p1_wins = p1_font.render(score_o.rjust(len_x, " ").rstrip("\n"), True, "#000000")
                window.blit(p1_wins, ((resolution - (y_reset + 60 + score_ofs * 18)), x_reset - 50))
                p2_wins = p2_font.render(score_x.rjust(len_o, " ").rstrip("\n"), True, "#000000")
                window.blit(p2_wins, ((resolution - (y_reset + 60 + score_ofs * 18)), x_reset - 25))

                ###result:
                score_font = pygame.font.Font(game_font, 24)
                if int(int(score_o) == int(fin_x[3])):
                    winner = "DRAW"
                    score = score_font.render(winner, True, "#000000")
                    print("DRAW")
                elif int(int(score_o) > int(fin_x[3])):
                    winner = p1_name[-1].split(".")[0] + " wins!" 
                    score = score_font.render(winner, True, "#000000")
                    print(p1_name[-1].split(".")[0], "WINS!")
                else:
                    winner = p2_name[-1].split(".")[0] + " wins!"
                    score = score_font.render(winner, True, "#000000")
                    print(p2_name[-1].split(".")[0], "WINS!")
                score_y = (resolution / 2) - ((len(winner) * 24) / 2)

                window.blit(score, (score_y, resolution - x_reset + 25))
                end = True

        ##react if one of the players can't play anymore
        rip = s.rstrip(":\n").split(" ")
        if "Piece" in rip[0]:
            s = return_next_line(int(rip[1]) + 1)
        #print(piece)
        #print(piece_x, piece_y)

        for event in pygame.event.get():
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_SPACE and paused == False:
                    print("||")
                    window.blit(pause_img, (y_reset, x_reset - 25))
                    pygame.display.update()
                    if not pause_game():
                        is_playing = False
                    elif game_speed == 50:
                        print(">")
                    else:
                        print(">>")
                if event.key == pygame.K_UP and game_speed == 50:
                    print(">>")
                    game_speed = 10
                if event.key == pygame.K_DOWN and game_speed == 10:
                    print(">")
                    game_speed = 50
                if event.key == pygame.K_ESCAPE:
                    print("Exiting the game...")
                    is_playing = False
            if event.type == pygame.QUIT:
                print("Exiting the game...")
                is_playing = False

        ###play, pause, fastforward test:
        if game_speed == 50 and not paused:
            window.blit(play_img, (y_reset, x_reset - 25))
        if game_speed == 10 and not paused:
            window.blit(ff_img, (y_reset, x_reset - 25))

        pygame.display.update()

        if paused:
            print("||")
            window.blit(pause_img, (y_reset, x_reset - 25))
            pygame.display.update()
            if not pause_game():
                is_playing = False
            else:
                print(">")
                paused = False

        pygame.time.wait(game_speed)

###main menu:
is_running = True
start = True
while is_running:
    window.blit(bg_main, (0, 0))
    window.blit(logo_img, (100, 340))
    
    if start and start_button.draw(window):
        start_button_d.draw(window)
        pygame.display.update()
        pygame.time.wait(240)
        print("PLAY")
        play()
        start = False
    if not start:
        by_font = pygame.font.Font(game_font, 18)
        by_who = by_font.render("by altikka", True, "#38c5f8")
        #window.blit(by_who, (220, 510))
        window.blit(by_who, (610, 10))#was 10, 10
        bye_font = pygame.font.Font(game_font, 16)
        bye = bye_font.render("Press 'Esc' to exit", True, "#000000")
        bye_y = (resolution / 2) - ((len("Press 'Esc' to exit") * 16) / 2)
        window.blit(bye, (bye_y, 530))

    for event in pygame.event.get():
        if event.type == pygame.KEYDOWN:
            if event.key == pygame.K_RETURN and start:
                start_button_d.draw(window)
                pygame.display.update()
                pygame.time.wait(240)
                print("PLAY")
                play()
                start = False
            if event.key == pygame.K_ESCAPE:
                print("Quitting...")
                is_running = False
        if event.type == pygame.QUIT:
            print("Quitting...")
            is_running = False

    pygame.display.update()

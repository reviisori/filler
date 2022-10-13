# FILLER

```
███████ ██ ██      ██      ███████ ██████  
██      ██ ██      ██      ██      ██   ██ 
█████   ██ ██      ██      █████   ██████  
██      ██ ██      ██      ██      ██   ██ 
██      ██ ███████ ███████ ███████ ██   ██
```

**Inroduction**

**Filler** is a project about algorithmic game, purpose of which is to fill a fixed sized grid with pieces of random size and shape. Pieces can’t be stacked more than one square above each other and they can’t exceed the grid. If these conditions are not met - the game ends.

The game is played between two players taking turns at placing a piece. Each successfully placed piece yields a number of points. The goal of the game is get the highest score possible. During the game each player attempts to place as many pieces as possible on the grid while attempting to prevent his opponent from doing the same. At the end of the game, the player with the most points wins the match.

The game itself is played on a host VM provided with the subject. Each turn MV gives the player in turn information about the grid, its size and current state. It also tells the player what kind of piece needs to be placed on the aforementioned grid. Player’s objective is to answer the MV with a set of coordinates after which it’s the other player’s turn to do the same with the next given piece.

**Usage**

Compile the executable with Makefile:

```bash
make && make clean
```

To run the program against another player, launch it from the root of the repository:

```bash
./resources/filler_vm -p1 ./altikka.filler -p2 ./resources/players/carli.filler -f ./resources/maps/map02
```

## **Initial Thoughts | The Approach**

After going over the subject documentation and discussing it with my peers this project could be divided into three clear parts:

#### **Part I - Gathering information & debugging**

In order to be even able to place a single piece on the grid one had to figure out the state of the ongoing game and all the information regarding the grid and the piece to be placed. The host MV communicates with the player’s program via STDIN in the following matter:

<img width="300" alt="frm_p1" src="https://user-images.githubusercontent.com/77926655/195689934-7973647c-ad22-4de8-9403-44b9ef4ad8d2.png">

The most straight forward approach for gathering information was to read the STDIN and parse the data for a later use. For this, one of the previously made functions [get_next_line] could be handily used. Testing it required efficient and clear logging system, on which I relied on throughout the entire project.

#### **Part II - Choosing the strategy**

After parsing the data, the next obvious step was to figure out a winning strategy for placing a given piece on the grid. Placing one randomly just wasn’t a viable option. By far the most prominent solution was to use some sort of heat map.

The map itself can be created  using integers or characters. After seeing it for the first time in ASCII I just couldn’t resist. It was just so much more aesthetic and pleasing to the eye:

<img width="1155" alt="frm_p2" src="https://user-images.githubusercontent.com/77926655/195690078-4eae7542-cea9-46e6-956e-d81b6c8cd54a.png">

#### **Part III - Placing the piece**

With all the data and a heat map at my disposal all that was left to do was place the given piece on the best possible spot on the map. All legal spots were compared against each other and the one that emitted the hottest heat signature was chosen each turn. This together with a couple of optimisations yielded a very strong strategy that most of the time boxed in the opponent quite efficiently:

<img width="790" alt="frm_p3-1" src="https://user-images.githubusercontent.com/77926655/195690234-692e98e4-4e80-40f2-83a5-72cae93a2068.png">

**Bonus — Visualisation**

To challenge myself properly I decided to pick up a completely new programming language for this part. The visualisation for this project was done using Python and its pygame module. All the assets were hand-crafted or hand-picked to give it a retro style appearance:

https://user-images.githubusercontent.com/77926655/195690584-f93c49a8-6b78-4bd4-ae97-5a569aab275f.mov

**Usage — Visualiser**

To run the visualiser you need to first install pygame:

```bash
pip install pygame
```

After installing pygame you can run the program from the `visualiser` directory:

```bash
../resources/filler_vm -p1 ../altikka.filler -p2 ../resources/players/carli.filler -f ../resources/maps/map02 | python3 main.py
```

## **Final Thoughts**

Learning how to create a proper logging and debugging tools for a program was one of the most significant things I took away from this project. Also constructing the architecture of the program in such a way, that the error trace can be easily followed to the root of the problem at any point was an invaluable skill to learn. Getting acquainted with a completely new programming language was also a huge learning experience that broadened my coding expertise as a whole.

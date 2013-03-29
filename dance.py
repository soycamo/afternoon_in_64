import pynes

from pynes.bitbag import *  

if __name__ == "__main__":
    pynes.press_start()
    exit()


palette = [
    0x22,0x29, 0x1A,0x0F, 0x22,0x36,0x17,0x0F,  0x22,0x30,0x21,0x0F,  0x22,0x27,0x17,0x0F,
    0x22,0x16,0x27,0x18,  0x22,0x1A,0x30,0x27,  0x22,0x16,0x30,0x27,  0x22,0x0F,0x36,0x17]

#altpalette = [
#    0x22,0x29, 0x1A,0x0F, 0x22,0x36,0x17,0x0F,  0x22,0x30,0x21,0x0F,  0x22,0x27,0x17,0x0F,
#    0x22,0x16,0x27,0x18,  0x22,0x1A,0x30,0x27,  0x22,0x16,0x30,0x27,  0x22,0x0F,0x36,0x17]

# Max addressable sprite is 256
chr_asset = import_chr('dance.chr')

secretary = define_sprite(100,90, [59,60,61,62,63,64], 0)
butchie = define_sprite(120,90, [144,145,146,147,148,149], 0)
#fluff = define_sprite(10,10, [154,83,153,155,156], 1)
star = define_sprite(0,0, [168,169, 170, 171], 0)

#fluff_x = rs(1)

def reset():
    wait_vblank()
    clearmem()
    wait_vblank()
    load_palette(palette)
    # When a sprite is set to 0, you can only set 4 tiles as a sprite. Go figure!
    load_sprite(star, 0)
    load_sprite(secretary, 4)
    load_sprite(butchie, 12)

def joypad1_up():
    get_sprite(secretary).y += 1
    get_sprite(butchie).y += 1

def joypad1_down():
    get_sprite(secretary).y -= 1
    get_sprite(butchie).y -= 1

def joypad1_left():
    get_sprite(secretary).x -= 1
    get_sprite(butchie).x += 1

def joypad1_right():
    get_sprite(secretary).x += 1
    get_sprite(butchie).x -= 1

def joypad1_a():
    get_sprite(star).y += 11

def joypad1_b():
    get_sprite(star).x -= 11

def joypad1_select():
    get_sprite(star).x += 22

#def nmi():
#    if star_x > 200:
#        star_x = 0

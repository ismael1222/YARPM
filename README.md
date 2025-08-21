# YARPM (ON HOLD)

Yet Another Rich Presence Manager, duh.

~~This time it works, not like the others 😒~~

I Have Become What I Swore to Destroy

## newz

Bad news people. discord's SDK is for Javascript. and uhh, this doesn't use javascript that way

What this means? the project will be on hold while i develop a lib for comms between c++ and discord

But hey, this project was "Let's see what can  do with c++" and this obstacle is just another step on discovering my capabilities.

What can you do:

If you know c++, you could throw an eye at the new repo ill do for the lib.

## Backstory

I opened GIMP, discod didnt recognize it. added it manually, it transformed into whatever the window name was, which instead of being `"GIMP"`, it was something like

```"GNU Image Manipulation Program – [Layer 1 copy #38] – Untitled.xcf (RGB, 12 layers) 50% (Indexed Color, 256 colors, 1 channel)"```

which we both know it doesnt look good.

I searched the web, but no linux-supported non-abandoned answers were found. so i made it myself

## The idea

The idea is easy:

C++ to take processes and list them. replace processName (`gimp`) to something that doesn't make your eyes bleed (`GIMP`) OR anyting you could want (`Edithing photos`, `Free Photoshop`, `GIMP > Ps`, `Drawing anime`), or anything else **(dont use slurs, you'll get nuked)**

And i thought (yes sometimes i do that): Why only names? lets go all in: GUI, custom name, custom Image, custom time, custom type, custom anything you're allowed to customize. and this is it.

## IOU

You cant right now.

~~This is the first commit, wait a few years and you'll be dissappointed, i mean, you seriously expected something from me?~~

### TO-DO

- [X] Window prototype
  - [X] Integrate webview.h
  - [X] Open basic window from main.cpp
  - [X] Do an alert on the HTML FROM main.cpp

- [X] HTML
  - [X] Load index.html
  - [X] Looks good?

- [X] C++ <=> JS
  - [X] Create a function in C++ for JS to call
  - [X] Back and forth: C++ to JS and JS' response to C++

- [ ] Processes backend
  - [X] Scan processes list
  - [X] Filter non-supported processes
  - [X] Send supported processes list to JS
  - [ ] ~~Option to show all processes, even unsupported ones~~ on hold until GUI is ready

- [ ] Styling and functionability
  - [X] Basic styling
  - [ ] Menu items/labels
  - [ ] Show processes instead of placeholders
  - [ ] Save custom settings
  - [ ] Show RPC Preview

- [ ] Discord connection
  - [ ] Implement IPC or Game SDK
  - [ ] Send activity to Discord APP
  - [ ] Update RP

<details>
<summary>Idea (dont read plz)</summary>
<details>
<summary>Como va a andar</summary>
<pre>
Primero que todo se va a tener que usar un appID generico
Si tenes discord, tnes developer account
poner en APP NAME siempre YARPM con un tick "Custom Name" siendo este actibable para poner una APPID
la custion esque va a haber un ?? para ver como conseguir uno y ponerle el name que quieras
la idea seria poner gifa mostrando donde hacer click, y decir que para cada nombre debe poner un appID diferente, y no debe ser muy dificil dado que tampoco vas a estar usando tantas apps lol
entonces: use YARPM or custom when issued
everything else is ok
should also store it on defaultJSON?
i dont think so, maybe tener el coso puesto pero vacio, y a la hora de copiarlo al userJSON se le agrega el default (no existe = crear, existeVacio = rellenar)

</pre>
</details>
Lista de procesos soportados/agregados que alguna vez han estado activos

Lista de procesos soportados/agregados que estan activos actualmente, golden surrounding el que esta currently showing (because of esta primero en el orden de prioridad)

la prioridad se "guarda" como la posicion en el json de ese item, asi no tengo que cambiar la prioridad en numeros (plus, si el usuario pone el de abajo del todo a arriba del todo, tendria que cambiar todos los numeros de todos los items. esta solucion lo hace "automaticamente" ya que se lleva por la posicion del item)
</details>

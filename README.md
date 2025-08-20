# YARPM

Yet Another Rich Presence Manager, duh.

This time it works, not like the others 😒

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
  - [ ] Scan processes list
  - [ ] Filter non-supported processes
  - [ ] Send supported processes list to JS
  - [ ] Option to show all processes, even unsupported ones

- [ ] Basic UI
  - [ ] Show processes list
  - [ ] Allow toggle and priority order
  - [ ] Prepare structure for custom RichPresence items

- [ ] Discord connection
  - [ ] Implement IPC or Game SDK
  - [ ] Send activity to Discord APP
  - [ ] Update RP

- [ ] Optimization and styling
  - [ ] Upgrade style (make it look cool)
  - [ ] Doc and clean
  - [ ] Do release for easy install

<details>
<summary>Idea (dont read plz)</summary>
Menu de settings
 Foto,

 nombre,

 tipo(jugando, escuchando, etc),

 hora de inicio,

 enable/disable show,

 showDespiteKnownForBeingMinimizable (Gris si es steam o Telegram o algo asi, se puede activar. mientras no este activo, enable/disable estará bloqueado en disable),

 Descripcion,

 eliminar // (reset defaults si esta el proceso en defaultJson, no dejarle eliminarlo)

Lista de procesos soportados/agregados que alguna vez han estado activos

Lista de procesos soportados/agregados que estan activos actualmente, golden surrounding el que esta currently showing (because of esta primero en el orden de prioridad)

la prioridad se "guarda" como la posicion en el json de ese item, asi no tengo que cambiar la prioridad en numeros (plus, si el usuario pone el de abajo del todo a arriba del todo, tendria que cambiar todos los numeros de todos los items. esta solucion lo hace "automaticamente" ya que se lleva por la posicion del item)
</details>

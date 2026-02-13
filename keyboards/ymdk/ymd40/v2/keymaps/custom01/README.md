
---

# YMD40 v2 — QMK keymap `custom01`

Keymap avanzado para teclado **40% ortolineal YMD40 v2** orientado a:

* Escritura eficiente con capas y mod-tap
* Uso intensivo de **tmux** e **i3**
* Trabajo sin ratón
* Escritura con **una sola mano** mediante `swap_hands`
* Macros de sistema con **Leader**
* Unicode / emojis
* Mayúsculas puntuales sin depender de la mano derecha

---

## 🧠 Filosofía del diseño

Este teclado está pensado para:

* No mover las manos de la fila base
* No depender de la mano derecha para funciones críticas
* Tener acceso inmediato a terminal, tmux, i3 y navegación
* Mantener el firmware ligero y mantenible

---

## 🧱 Conceptos clave

1. Capas muy especializadas
2. Teclas duales (tap / hold) en la capa base
3. Leader key para comandos de sistema y tmux
4. `swap_hands` para escritura en espejo
5. **One-Shot Shift** para una sola mayúscula en modo espejo
6. Alt-Tab / Win-Tab en modo “multitab” (auto-release por tiempo)

---

## ⌨️ Capa base — `_QWERTY`

Es la capa de escritura normal.

Muchas teclas son **mod-tap / layer-tap**:

* **Tap** → letra
* **Hold** → modificador o cambio de capa

Aquí se escribe el 90% del tiempo.

---

## 🧭 Leader key (solo en `_QWERTY`)

La tecla Leader activa temporalmente una capa técnica (`_QWERTY2`) sin mod-tap para evitar interferencias durante la secuencia.

Al terminar Leader, el teclado **vuelve automáticamente** a `_QWERTY`.

### Secuencias destacadas

| Secuencia          | Acción              |
| ------------------ | ------------------- |
| Leader + **T**     | Abrir terminal      |
| Leader + **S**     | Captura de pantalla |
| Leader + **C**     | Calculadora         |
| Leader + **L**     | Bloqueo de sesión   |
| Leader + **M + …** | Comandos tmux       |

---

## 🧩 TMUX desde el teclado (Leader → M)

Tras `Leader` + `M`:

| Tecla   | Acción tmux       |
| ------- | ----------------- |
| `H`     | Split horizontal  |
| `V`     | Split vertical    |
| `X`     | Cerrar pane       |
| Flechas | Mover entre panes |
| `Z`     | Zoom pane         |

> Los bindings están elegidos para no depender de símbolos conflictivos con layout ES.

---

## 🔁 Swap Hands — Escritura en espejo

Una tecla activa `swap_hands_on`, que refleja el teclado:

* Las teclas de la derecha pasan a la izquierda
* Permite escribir palabras completas con una sola mano

### 🔠 Mayúscula en modo espejo (clave)

La tecla **Shift/Caps** es un **Tap Dance especial**:

| Acción | Resultado                                            |
| ------ | ---------------------------------------------------- |
| 1 tap  | **One-Shot Shift** → la siguiente letra en mayúscula |
| 2 taps | Caps Lock normal                                     |
| Hold   | Shift mantenido mientras se sostiene                 |

Esto está diseñado específicamente para escribir en espejo sin usar la mano derecha.

---

## 🔄 Alt-Tab y Win-Tab inteligentes

Teclas dedicadas `ALTTAB` y `WINTAB`:

* Primera pulsación → mantiene Alt / Win
* Puedes pulsar Tab varias veces
* Si pasan ~800 ms sin pulsar → se libera automáticamente

No se quedan mods “pegados”.

---

## 🗂️ Capas principales

| Capa                     | Uso                        |
| ------------------------ | -------------------------- |
| `_LOWER`                 | Símbolos y navegación      |
| `_RAISE`                 | Números y funciones        |
| `_MOV` / `_MOV2`         | Movimiento estilo Vim / i3 |
| `_NUM_PAD` / `_RNUM_PAD` | Numpad completo            |
| `_MOUSE`                 | Ratón desde teclado        |
| `_FUNCTION_KEYS`         | F1–F12 y extras            |
| `_I3`                    | Atajos específicos de i3   |
| `_EMOJIS`                | Unicode / emojis           |

---

## 😀 Unicode / Emojis

Capa dedicada con `UNICODEMAP` para insertar símbolos y emojis frecuentes.

---

## 🛡️ Boot keep-alive anti screenlock

Durante el arranque, el teclado puede generar actividad mínima para evitar que el sistema bloquee la pantalla (uso tipo kiosko).

---

## ⚙️ Estado del firmware

Configuración optimizada para tamaño:

```
22234 / 28672 bytes (77%) — ~6.4 KB libres
```

Se han desactivado componentes pesados (RGB, backlight, debug…) para mantener margen.

---

## 🧰 Mantenimiento futuro

Si el firmware vuelve a acercarse al límite:

1. Revisar tamaño de `unicode_map`
2. Evitar duplicar capas completas
3. Mantener `LTO_ENABLE = yes`
4. No reactivar RGB/backlight salvo necesidad real

---

## 🧭 Resumen mental rápido

* Escribes normal en `_QWERTY`
* Leader para sistema y tmux
* Swap hands para escribir con una mano
* One-Shot Shift para una sola mayúscula
* Capas para todo lo demás

---

Este keymap está pensado para sesiones largas, trabajo intensivo en terminal/i3/tmux y máxima eficiencia con un 40%.


/* 
 * Customización teclado YMD40 por Santiago Intxausti <intxausti@gmail.com>
 */

#include QMK_KEYBOARD_H
#ifdef UNICODEMAP_ENABLE
#    include "process_unicode.h"  // opcional, pero ayuda al autocomplete
#    define X(n)        UM(n)
#    define XP(n, s)    UP(n, s)
#endif






//Unicode Keys
enum unicode_names {
    ORDINAL_MALE,
	ORDINAL_FEMALE,
	RAYA,
    SMAILING,
    GRINNING,
    BEAMING,
    ROLLING,
    WINKING,
    HALO,
    HEARTS,
    HEARTEYES,
    KISS,
    ZANY,
    OPENHANDS,
    HANDMOUTH,
    PEEKINGEYE,
    SHUSHING,
    THINKING,
    SALUTING,
    EYEBROW,
    SPLODING,
    SUNGLASES,
    YAWNING,
    ANGRY,
    ASTONISHED,
    SAD,
    CHESS,
    HAMMER_SICKLE,
    CUP
    
    
};

#define I3_WS1  LGUI(KC_1)
#define I3_WS2  LGUI(KC_2)
#define I3_WS3  LGUI(KC_3)
#define I3_WS4  LGUI(KC_4)
#define I3_WS5  LGUI(KC_5)
#define I3_WS6  LGUI(KC_6)
#define I3_WS7  LGUI(KC_7)
#define I3_WS8  LGUI(KC_8)
#define I3_WS9  LGUI(KC_9)

#define I3_MV1  LSFT(LGUI(KC_1))
#define I3_MV2  LSFT(LGUI(KC_2))
#define I3_MV3  LSFT(LGUI(KC_3))
#define I3_MV4  LSFT(LGUI(KC_4))
#define I3_MV5  LSFT(LGUI(KC_5))
#define I3_MV6  LSFT(LGUI(KC_6))
#define I3_MV7  LSFT(LGUI(KC_7))
#define I3_MV8  LSFT(LGUI(KC_8))
#define I3_MV9  LSFT(LGUI(KC_9))

#define I3_FL   LGUI(KC_H)                 // focus left  (según tu i3: Mod+h)
#define I3_FD   LGUI(KC_J)                 // focus down
#define I3_FU   LGUI(KC_K)                 // focus up
#define I3_FR   LGUI(KC_L)                 // focus right

#define I3_ML   LSFT(LGUI(KC_H))           // move left   (Mod+Shift+h)
#define I3_MD   LSFT(LGUI(KC_J))
#define I3_MU   LSFT(LGUI(KC_K))
#define I3_MR   LSFT(LGUI(KC_L))

#define I3_TERM LGUI(KC_ENT)               // Mod+Enter
#define I3_MENU LGUI(KC_D)                 // Mod+Space
#define I3_KILL LSFT(LGUI(KC_Q))           // Mod+Shift+q
#define I3_FULL LGUI(KC_F)                 
#define I3_FLOT LSFT(LGUI(KC_SPC))         // Mod+Shift+Space (toggle floating) o cambia a LGUI(KC_SPC) si lo tienes así






//Custom Macro Keys
enum custom_keycodes {
  ALTTAB = SAFE_RANGE,
  WINTAB,
  DEL_LWORD,
  DEL_RWORD,
  DEL_LINE,
  DEL_END_LINE,
  UP_NEW_LINE,
  DOWN_NEW_LINE,
  LENS_UP,
  LENS_DOWN,
  LENS_CLOSE,
  UNIX_HOME,
  ONOFFBOT,
  HTTPS,
  HTTP,
  FTP,
  KVM01,
  KVM02,
  KVM03
};

// -----------------------------------------------------------------------------
// Alt-Tab / Win-Tab en "modo": mantiene el modificador un rato para poder
// tabear varias veces. Se libera automáticamente por timeout.
// -----------------------------------------------------------------------------
#define MODTAB_TIMEOUT_MS 800

static bool     alttab_active = false;
static uint16_t alttab_timer  = 0;

static bool     wintab_active = false;
static uint16_t wintab_timer  = 0;



//TapDance Functions
enum {
	TD_SIFT_CAPSLOCK,
	TD_RHAND_LAYER,
	TD_WIN_MENU,
	TD_MNXT,
	TD_PLAY,
	TD_VOLD,
	TD_VOLU,
	TD_ESC,
	TD_SFT_MOV,
	TD_CTL_MOV,
	TD_LPRN,
	TD_RPRN,
	TD_TAB,
	TD_SPACE

};




//Layers
enum layer_names {
  _QWERTY,
  _LOWER,
  _RAISE,
  _OTHERS,
  _MOV,
  _MOV2,
  _NUM_PAD,
  _RNUM_PAD,
  _MOUSE,
  _FUNCTION_KEYS,
  _FUNCTION2_KEYS,
  _EMOJIS,
  _I3,
  _QWERTY2
};




const uint32_t PROGMEM unicode_map[] = {
    
    [ORDINAL_MALE] = 0xBA, // º
    [ORDINAL_FEMALE]  = 0xAA,  // ª
	[RAYA] = 0x2014, // —
 	[SMAILING] = 0x1F642, // 🙂
    [GRINNING]  = 0x1F600,  // 😀
    [BEAMING] = 0x1F601,  // 😁
    [ROLLING]  = 0x1F923, // 🤣
    [WINKING] = 0x1F609, // 😉
    [HALO] = 0x1F607, // 😇
    [HEARTS] = 0x1F970, // 🥰
    [HEARTEYES] = 0x1F60D, // 😍
    [KISS] = 0x1F618, // 😘
    [ZANY] = 0x1F92A, // 🤪
    [OPENHANDS] = 0x1F917, // 🤗
    [HANDMOUTH] = 0x1FAE2, // 🫢
    [PEEKINGEYE] = 0x1FAE3, // 🫣
    [SHUSHING] = 0x1F92B, // 🤫
    [THINKING] = 0x1F914, // 🤔
    [SALUTING] = 0x1FAE1, // 🫡
    [EYEBROW] = 0x1F928, // 🤨
    [SPLODING] = 0x1F92F, //  🤯
    [SUNGLASES] = 0x1F60E, // 😎
    [YAWNING] = 0x1F971, // 🥱
    [ANGRY] = 0x1F621, // 😡
    [ASTONISHED] = 0x1F632, // 😲	
    [SAD] = 0x1F625, // 😥
    [CHESS] = 0x265F, // ♟
    [HAMMER_SICKLE] = 0x262D, // ☭
    [CUP] = 0x2615, // ☕  
          
};




static void handleBoot(void);
static uint32_t key_timer_boot = 0;
uint32_t tiempo_boot = 0;
bool is_boot_active = false;





const keypos_t PROGMEM hand_swap_config[MATRIX_ROWS][MATRIX_COLS] = {
  {{11, 0}, {10, 0}, {9, 0}, {8, 0}, {7, 0}, {6, 0}, {5, 0}, {4, 0}, {3, 0}, {2, 0}, {1, 0}, {0, 0}},
  {{11, 1}, {10, 1}, {9, 1}, {8, 1}, {7, 1}, {6, 1}, {5, 1}, {4, 1}, {3, 1}, {2, 1}, {1, 1}, {0, 1}},
  {{11, 2}, {10, 2}, {9, 2}, {8, 2}, {7, 2}, {6, 2}, {5, 2}, {4, 2}, {3, 2}, {2, 2}, {1, 2}, {0, 2}},
  {{11, 3}, {10, 3}, {9, 3}, {8, 3}, {7, 3}, {6, 3}, {5, 3}, {4, 3}, {3, 3}, {2, 3}, {1, 3}, {0, 3}},
};




const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_QWERTY]=LAYOUT_ortho_4x12(
			TD(TD_RHAND_LAYER),		RGUI_T(KC_Q),		RALT_T(KC_W),		RCTL_T(KC_E),		RSFT_T(KC_R),		LT(_MOUSE,KC_T),	KC_Y,			RSFT_T(KC_U),		RCTL_T(KC_I),	RALT_T(KC_O),	RGUI_T(KC_P),			KC_BSPC,
			TD(TD_ESC),			LT(_MOV,KC_A),		LALT_T(KC_S),		LCTL_T(KC_D),		LSFT_T(KC_F),		LT(_MOV2,KC_G),		KC_H,			LSFT_T(KC_J),		LCTL_T(KC_K),	LALT_T(KC_L),	LT(_FUNCTION_KEYS,KC_SCLN),	LT(_FUNCTION2_KEYS,KC_QUOT),
			OSM(MOD_LCTL),			LGUI_T(KC_Z),		KC_X,			TD(TD_CTL_MOV),		TD(TD_SFT_MOV),		KC_B,			KC_N,			KC_M,			KC_COMM,	KC_DOT,		LGUI_T(KC_SLSH),		QK_LEAD,
			OSM(MOD_LGUI),			OSM(MOD_LALT),		OSM(MOD_RALT),		TD(TD_SIFT_CAPSLOCK),	TD(TD_TAB),		TD(TD_SPACE),		TD(TD_SPACE),		LT(_RAISE,KC_ENT),	MO(_EMOJIS),	TD(TD_PLAY),	TD(TD_VOLU),			TD(TD_VOLD)
	),
    
	[_EMOJIS]=LAYOUT_ortho_4x12(
		X(HAMMER_SICKLE),	X(SMAILING),	X(GRINNING),	X(BEAMING),		X(ROLLING),	KC_NO,			KC_NO,			KC_NO,		X(EYEBROW),	X(SAD),			X(ANGRY),	KC_NO,
		X(CHESS),		X(WINKING),	X(KISS),	X(HEARTS),		X(HEARTEYES),	KC_NO,			KC_NO,			KC_NO,		X(ASTONISHED),	X(HANDMOUTH),		X(PEEKINGEYE),	KC_NO,
		X(CUP),			X(SUNGLASES),	X(HALO),	X(ZANY),		X(SPLODING),	KC_NO,			KC_NO,			KC_NO,		X(OPENHANDS),	KC_NO,			KC_NO,		KC_NO,
		X(SALUTING),		X(THINKING),	X(SHUSHING),	X(YAWNING),		MO(_OTHERS),	SH_T(KC_SPACE),		SH_T(KC_SPACE),		KC_TRNS,	KC_NO,		KC_NO,			KC_NO,		KC_NO
	),

	[_RAISE]=LAYOUT_ortho_4x12(
			KC_NO,	HTTPS,	HTTP,	FTP,	KC_NO,	KC_NO,		RSA(KC_GRV),	RALT(KC_1),	RALT(KC_2),	RALT(KC_3),	RALT(KC_4),	RALT(KC_5),
			KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,		RALT(KC_SCLN),	RALT(KC_6),	RALT(KC_7),	RALT(KC_8),	RALT(KC_LBRC),	RALT(KC_RBRC),
			KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,		KC_NO,		RALT(KC_MINS),	RALT(KC_EQL),	RALT(KC_BSLS),	RALT(KC_9),	RALT(KC_0),
			KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_TAB,	KC_SPACE,	KC_SPACE,	KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO
	),			
			  
     	[_LOWER]=LAYOUT_ortho_4x12(
			KC_DEL,		KC_NO,		LENS_CLOSE,	LENS_DOWN,	LENS_UP,        DM_PLY1,	KC_GRV,		 			KC_EXLM,	KC_AT,		KC_HASH,	KC_DLR,		KC_PERC,
			KC_ENT,		WINTAB,		ALTTAB,	    	C(G(KC_LEFT)),	C(G(KC_RIGHT)),	DM_PLY2,	RSA(KC_SCLN),				KC_CIRC,	KC_AMPR,	KC_ASTR,	TD(TD_LPRN),	TD(TD_RPRN),
			KC_NO,		KC_NO,		KC_NO,		G(S(KC_S)),	C(S(KC_V)),	G(KC_V),	XP(ORDINAL_MALE,ORDINAL_FEMALE),	KC_MINS,	KC_EQL,		KC_BSLS,	UNIX_HOME,	X(RAYA),
			KC_NO,		KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_NO,		KC_NO,		 			MO(_OTHERS),	RALT(KC_5),	KC_NO,		KC_NO,		KC_NO
	),
    
   	[_FUNCTION_KEYS]=LAYOUT_ortho_4x12(
			KC_PSCR,	KC_F1,		KC_F2,		KC_F3,		KC_F4,		KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,
			KC_SCRL,	KC_F5,		KC_F6,		KC_F7,		KC_F8,		KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,
			KC_PAUS,	KC_F9,		KC_F10,		KC_F11,		KC_F12,		KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,
			KC_NO,		KC_NO,		KC_NO,		KC_NO, 		KC_TRNS,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO
	),
		
	[_FUNCTION2_KEYS]=LAYOUT_ortho_4x12(
			KC_PSCR,	KC_F13,		KC_F14,		KC_F15,		KC_F16,		KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,
			KC_SCRL,	KC_F17,		KC_F18,		KC_F19,		KC_F20,		KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,
			KC_PAUS,	KC_F21,		KC_F22,		KC_F23,		KC_F24,		KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,
			KC_NO,		KC_NO,		KC_NO,		KC_NO, 		KC_TRNS,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO 
	),
	
	[_OTHERS]=LAYOUT_ortho_4x12(
			QK_BOOT,	KC_NO,		KC_NO,		KC_NO,		KC_NO,		DM_REC1,	KC_NO,	ONOFFBOT,	KC_NO,		KC_PWR,		KC_SLEP,	KC_WAKE,
			QK_RBT,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		DM_REC2,	KC_NO,	KVM01,		KVM02,		KVM03,		KC_NO,		KC_NO,
			QK_MAKE,	KC_NO,		KC_NO,		KC_BRID,	KC_BRIU,	DM_RSTP,	KC_NO,	DT_DOWN,	DT_PRNT,	DT_UP,		KC_NO,		KC_NO,
			KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_NO,		KC_NO,	KC_TRNS,	KC_NO,		KC_NO,		KC_NO,		KC_NO
	),

	[_MOV]=LAYOUT_ortho_4x12(
			KC_NO,			KC_NO,			KC_NO,			KC_NO,			KC_NO,		KC_NO,		KC_PAUS,	KC_HOME,	KC_INS,		KC_PGUP,		KC_NO,			KC_BSPC,
			KC_NO,			KC_TRNS,		KC_LALT,		KC_LCTL,		KC_LSFT,	KC_LGUI,	KC_LEFT,	KC_DOWN,	KC_UP,		KC_RGHT,		KC_NO,			KC_NO,
			KC_NO,			KC_NO,			KC_NO,			KC_TRNS,		KC_TRNS,	KC_NO,		KC_NO,		KC_END,		KC_DEL,		KC_PGDN,		KC_NO,			KC_NO,
			KC_NO,			KC_NO,			KC_NO,			KC_NO,			KC_TAB,		KC_SPACE,	KC_SPACE,	KC_ENT,		DEL_LINE,	DEL_LWORD,		DEL_END_LINE,	KC_NO
	),

	[_MOV2]=LAYOUT_ortho_4x12(
			KC_NO,			KC_NO,			KC_NO,			KC_NO,			KC_TRNS,	KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,			KC_NO,	KC_NO,
			KC_NO,			KC_NO,			KC_NO,			KC_NO,			KC_NO,		KC_NO,		DEL_LWORD,	DEL_END_LINE,	DEL_LINE,	DEL_RWORD,		KC_NO,	KC_NO,
			KC_NO,			KC_NO,			KC_NO,			KC_NO,			KC_NO,		KC_NO,		KC_NO,		UP_NEW_LINE,	KC_NO,		KC_NO,			KC_NO,	KC_NO,
			KC_NO,			KC_NO,			KC_NO,			KC_NO,			KC_TAB,		KC_SPACE,	KC_SPACE,	DOWN_NEW_LINE,	KC_NO,		KC_NO,			KC_NO,	KC_NO
	),
	
	
	[_RNUM_PAD]=LAYOUT_ortho_4x12(
			TD(TD_RHAND_LAYER),			KC_PMNS,	KC_PAST,	KC_PSLS,	KC_NUM,		KC_ESC,				KC_ESC,			KC_P7,	KC_P8,	KC_P9,		KC_PPLS,	KC_BSPC,
			LM(_QWERTY2,MOD_LALT),		 	KC_NO,		KC_NO,		KC_NO,		KC_AT,		KC_TAB,				KC_TAB,			KC_P4,	KC_P5,	KC_P6,		KC_PPLS,	KC_DEL,
			LM(_QWERTY2,MOD_LCTL),			KC_NO,		KC_NO,		KC_NO,		KC_PERC,	KC_COMM,			KC_COMM,		KC_P1,	KC_P2,	KC_P3,		KC_PENT,	KC_PEQL,
			LM(_QWERTY2,MOD_LCTL|MOD_LALT),		KC_NO,		KC_NO,		KC_NO,		KC_ENT,		SH_T(KC_SPACE),			SH_T(KC_SPACE),		KC_P0,	KC_P0,	KC_PDOT,	KC_PENT,	KC_PEQL
	),

	[_NUM_PAD]=LAYOUT_ortho_4x12(
			TD(TD_RHAND_LAYER),			KC_DEL,	KC_7,	KC_8,	KC_9,	KC_ESC,		KC_ESC,		KC_7,	KC_8,	KC_9,	KC_DEL,	KC_BSPC,
			LM(_QWERTY2,MOD_LALT),			KC_NO,	KC_4,	KC_5,	KC_6,	KC_TAB,		KC_TAB,		KC_4,	KC_5,	KC_6,	KC_ENT,	KC_NO,
			LM(_QWERTY2,MOD_LCTL),			KC_ENT,	KC_1,	KC_2,	KC_3,	KC_COMM,	KC_COMM,	KC_1,	KC_2,	KC_3,	KC_ENT,	KC_NO,
			LM(_QWERTY2,MOD_LCTL|MOD_LALT),		KC_ENT,	KC_DOT,	KC_0,	KC_0,	KC_SPACE,	KC_SPACE,	KC_0,	KC_0,	KC_DOT,	KC_ENT,	KC_NO
	),

[_MOUSE]=LAYOUT_ortho_4x12(
        KC_TRNS,    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      MS_BTN1,    MS_UP,      MS_BTN2,    MS_WHLU,    MS_ACL0,
        KC_TRNS,    KC_TRNS,    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      MS_LEFT,    MS_DOWN,    MS_RGHT,    MS_WHLD,    MS_ACL1,
        KC_TRNS,    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      MS_WHLL,    MS_BTN3,    MS_WHLR,    KC_NO,      MS_ACL2,
        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS
),
	
	[_I3]=LAYOUT_ortho_4x12(
  		KC_TRNS, 		I3_MV1,  I3_MV2,  I3_MV3,  I3_MV4, 	I3_MV5,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS,
  		KC_NO,	 		I3_MV6,  I3_MV7,  I3_MV8,  I3_MV9,   	KC_NO,    I3_FL,   I3_FD,   I3_FU,   I3_FR,   KC_NO,   KC_TRNS,
  		KC_NO,  		KC_NO,   KC_NO,   KC_NO,   KC_NO, 	I3_MV5,   I3_ML,   I3_MD,   I3_MU,   I3_MR,   KC_NO,   KC_TRNS,
		KC_TRNS, 		KC_NO,   KC_NO,   KC_NO,   KC_NO, 	KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS
	),
		

	[_QWERTY2]=LAYOUT_ortho_4x12(
		KC_TRNS,			KC_Q,		KC_W,		KC_E,		KC_R,		KC_T,		KC_Y,		KC_U,		KC_I,		KC_O,		KC_P,			KC_BSPC,
		KC_TRNS,			KC_A,		KC_S,		KC_D,		KC_F,		KC_G,		KC_H,		KC_J,		KC_K,		KC_L,		KC_SCLN,		KC_QUOT,
		KC_TRNS,			KC_Z,		KC_X,		KC_C,		KC_V,		KC_B,		KC_N,		KC_M,		KC_COMM,	KC_DOT,		KC_SLSH,		QK_LEAD,
		KC_TRNS,			KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TAB,		KC_SPACE,	KC_SPACE,	KC_ENT,		KC_TRNS,	KC_TRNS,	KC_TRNS,		KC_TRNS
	)
};




bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    
	switch (keycode) {

		case ALTTAB: 
			if (record->event.pressed) {
				// Activa Alt en modo "sticky" temporal
				if (!alttab_active) {
					alttab_active = true;
					register_code(KC_LALT);
				}
				alttab_timer = timer_read();
				tap_code(KC_TAB);
			}
			return false;


		case WINTAB:
			if (record->event.pressed) {
				// Activa GUI (Win) en modo "sticky" temporal
				if (!wintab_active) {
					wintab_active = true;
					register_code(KC_LGUI);
				}
				wintab_timer = timer_read();
				tap_code(KC_TAB);
			}
			return false;

		case DEL_LWORD: 

			if (record->event.pressed){

				SEND_STRING(SS_DOWN(X_LSFT) SS_DOWN(X_LCTL) SS_TAP(X_LEFT) SS_UP(X_LCTL) SS_UP(X_LSFT) SS_TAP(X_DEL));
				
			}

			break;

		case DEL_RWORD: 

			if (record->event.pressed){

				SEND_STRING(SS_DOWN(X_LSFT) SS_DOWN(X_LCTL) SS_TAP(X_RIGHT) SS_UP(X_LCTL) SS_UP(X_LSFT) SS_TAP(X_DEL));
				
			}

			break;
			
		case DEL_LINE: 

			if (record->event.pressed){
				
				SEND_STRING(SS_DOWN(X_LSFT) SS_TAP(X_HOME) SS_UP(X_LSFT) SS_TAP(X_DEL));
				
			}

			break;

		case DEL_END_LINE:

			if (record->event.pressed){
				
				SEND_STRING(SS_DOWN(X_LSFT) SS_TAP(X_END) SS_UP(X_LSFT) SS_TAP(X_DEL));
				
			}

			break;
			
		case DOWN_NEW_LINE:

			if (record->event.pressed){

				SEND_STRING(SS_TAP(X_END) SS_TAP(X_ENTER));
				
			}

			break;
			
		
		case UP_NEW_LINE:

			if (record->event.pressed){

				SEND_STRING(SS_TAP(X_HOME) SS_TAP(X_ENTER) SS_TAP(X_UP));
				
			}

			break;
			
		case LENS_UP:
			
			if (record->event.pressed){

				SEND_STRING(SS_DOWN(X_LGUI) SS_TAP(X_EQL) SS_UP(X_LGUI));
				
			}	

			break;
		
		case LENS_DOWN:
			
			if (record->event.pressed){

				SEND_STRING(SS_DOWN(X_LGUI) SS_TAP(X_MINS) SS_UP(X_LGUI));
				
			}	

			break;


		case LENS_CLOSE:
			
			if (record->event.pressed){

				SEND_STRING(SS_DOWN(X_LGUI) SS_TAP(X_ESC) SS_UP(X_LGUI));
				
			}	

			break;
							
		case UNIX_HOME:

			if (record->event.pressed){

			    // Limpia cualquier modificador residual (oneshot, stuck mods, etc.)
			    clear_mods();
			    clear_oneshot_mods();
			    clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);
			    send_keyboard_report();
			    wait_ms(30);

			    // Shift down
			    register_code(KC_LSFT);
			    send_keyboard_report();
			    wait_ms(40);

			    // ` down/up (con Shift = ~ en US)
			    register_code(KC_GRV);
			    send_keyboard_report();
			    wait_ms(40);
			    unregister_code(KC_GRV);
			    send_keyboard_report();
			    wait_ms(40);

			    // Shift up
			    unregister_code(KC_LSFT);
			    send_keyboard_report();
			    wait_ms(40);

			    tap_code(KC_SPACE);
			    wait_ms(20);
			   
			    // /
			    tap_code(KC_SLSH);
			    wait_ms(20);
				
				
			}	
			
			break;
					
			
		case ONOFFBOT:
			
			if (record->event.pressed){
			
				handleBoot();
			}
			break;
		
		case KVM01:
					
			if (record->event.pressed){

				SEND_STRING(SS_TAP(X_RCTL) SS_TAP(X_RCTL) SS_TAP(X_1) SS_TAP(X_ENT));
				
			}	

			break;
		
		case KVM02:
		
			if (record->event.pressed){

				SEND_STRING(SS_TAP(X_RCTL) SS_TAP(X_RCTL) SS_TAP(X_2) SS_TAP(X_ENT));
				
			}	

			break;
		
		case KVM03:
		
			if (record->event.pressed){

				SEND_STRING(SS_TAP(X_RCTL) SS_TAP(X_RCTL) SS_TAP(X_R) SS_TAP(X_ENT));
				
			}	

			break;
			
			
		case HTTPS:

			if (record->event.pressed){

				SEND_STRING("https://");
				
			}	
			
			break;
			
		case HTTP:

			if (record->event.pressed){

				SEND_STRING("http://");
				
			}	
			
			break;
			
		case FTP:

			if (record->event.pressed){

				SEND_STRING("ftp://");
				
			}	
			
			break;

		default:
			break;

	}	

	return true;
  
};




// FUNCION TECLA LEADER

void leader_start_user(void) {
	
	layer_on(_QWERTY2);
}

// -----------------------------------------------------------------------------
// Configuración tmux
// -----------------------------------------------------------------------------

// Delay (ms) entre el prefijo de tmux y la tecla de comando
#define TMUX_PREFIX_DELAY_MS 60

// Prefijo tmux por defecto: Ctrl + b
static inline void tmux_prefix(void) {
    tap_code16(LCTL(KC_B));
}

// Envía: prefijo -> espera -> tecla
static inline void tmux_cmd(uint16_t keycode) {
    tmux_prefix();
    wait_ms(TMUX_PREFIX_DELAY_MS);
    tap_code16(keycode);
}

// Envía: prefijo -> espera -> Shift+tecla (útil para % y ")
static inline void tmux_cmd_shifted(uint16_t keycode) {
    tmux_prefix();
    wait_ms(TMUX_PREFIX_DELAY_MS);
    tap_code16(S(keycode));
}

// -----------------------------------------------------------------------------
// Leader
// -----------------------------------------------------------------------------

void leader_end_user(void) {

    // Numkeyboard
    if (leader_sequence_one_key(KC_J)) {
        layer_move(_RNUM_PAD);
    }

    // ScreenShoot (Win: GUI+Shift+S)
    else if (leader_sequence_one_key(KC_S)) {
        tap_code16(LGUI(LSFT(KC_S)));
    }

    // Terminal (Ctrl+Alt+T)
    else if (leader_sequence_one_key(KC_T)) {
        tap_code16(LCTL(LALT(KC_T)));
    }

    // Notepad (Ctrl+Alt+N)
    else if (leader_sequence_one_key(KC_N)) {
        tap_code16(LCTL(LALT(KC_N)));
    }

    // Explorador Archivos (Ctrl+Alt+E)
    else if (leader_sequence_one_key(KC_E)) {
        tap_code16(LCTL(LALT(KC_E)));
    }

    // Chrome home page
    else if (leader_sequence_one_key(KC_H)) {
        tap_code16(LALT(KC_HOME));
        tap_code16(LALT(KC_0));
    }

    // Windows calculator
    else if (leader_sequence_one_key(KC_K)) {
        tap_code16(LCTL(LALT(KC_C)));
    }

    // Ctrl + Alt + Supr
    else if (leader_sequence_three_keys(KC_C, KC_A, KC_D)) {
        tap_code16(LCTL(LALT(KC_DEL)));
    }

    // Ctrl + Alt + Backspace
    else if (leader_sequence_three_keys(KC_C, KC_A, KC_B)) {
        tap_code16(LCTL(LALT(KC_BSPC)));
    }

    // Capslock
    else if (leader_sequence_three_keys(KC_C, KC_A, KC_P)) {
        tap_code(KC_CAPS);
    }

    // Caps lock / num lock / scroll lock OFF
    else if (leader_sequence_three_keys(KC_O, KC_F, KC_F)) {

        if (host_keyboard_led_state().num_lock) {
            tap_code(KC_NUM);
        }

        if (host_keyboard_led_state().scroll_lock) {
            tap_code(KC_SCROLL_LOCK);
        }

        if (host_keyboard_led_state().caps_lock) {
            tap_code(KC_CAPS_LOCK);
        }
    }

    // Close active windows
    else if (leader_sequence_three_keys(KC_C, KC_L, KC_S)) {
        tap_code16(LALT(KC_F4));
    }

    // -------------------------------------------------------------------------
    // tmux macros (Leader + ...)
    // -------------------------------------------------------------------------
    // Sugerencia de mapeo (típico):
    //   Leader + M  + C  -> new window      (prefix + c)
    //   Leader + M  + N  -> next window     (prefix + n)
    //   Leader + M  + P  -> prev window     (prefix + p)
    //   Leader + M  + X  -> kill pane       (prefix + x)
    //   Leader + M  + D  -> detach          (prefix + d)
    //   Leader + M  + S  -> choose session  (prefix + s)
    //   Leader + M  + V  -> split vertical  (prefix + %)
    //   Leader + M  + H  -> split horizontal(prefix + ")
    //
    // Nota: para % y " uso versiones con Shift (S(KC_5) y S(KC_QUOT)).
    // Ajusta si tu distribución/layout no corresponde a eso.

    // New window (prefix + c)
    else if (leader_sequence_two_keys(KC_M, KC_C)) {
        tmux_cmd(KC_C);
    }

    // Next window (prefix + n)
    else if (leader_sequence_two_keys(KC_M, KC_N)) {
        tmux_cmd(KC_N);
    }

    // Previous window (prefix + p)
    else if (leader_sequence_two_keys(KC_M, KC_P)) {
        tmux_cmd(KC_P);
    }

    // Kill pane (prefix + x)
    else if (leader_sequence_two_keys(KC_M, KC_X)) {
        tmux_cmd(KC_X);
    }

    // Detach (prefix + d)
    else if (leader_sequence_two_keys(KC_M, KC_D)) {
        tmux_cmd(KC_D);
    }

    // Choose session (prefix + s)
    else if (leader_sequence_two_keys(KC_M, KC_S)) {
        tmux_cmd(KC_S);
    }

    // Split vertical (prefix + %)  -> normalmente Shift+5 en US; en ES suele ser distinto
    else if (leader_sequence_two_keys(KC_M, KC_V)) {
        tmux_cmd_shifted(KC_5);
    }

    // Split horizontal (prefix + ") -> normalmente Shift+QUOTE en US; en ES suele ser distinto
    else if (leader_sequence_two_keys(KC_M, KC_H)) {
        tmux_cmd_shifted(KC_QUOT);
    }


    // IMPORTANTE: _QWERTY2 se activa en leader_start_user() como capa "técnica"
    // (sin teclas dual-role) y debe desactivarse siempre al salir de Leader.
    layer_off(_QWERTY2);
}




// FUNCIONES TAP DANCE

// Define a type for as many tap dance states as you need
typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD,
    TD_TRIPLE_TAP,
    TD_TRIPLE_HOLD
} td_state_t;

typedef struct {

    bool is_press_action;
    td_state_t state;
    
} td_tap_t;

// Declare the functions to be used with your tap dance key(s)

// Function associated with all tap dances
td_state_t cur_dance(tap_dance_state_t *state);

// Functions associated with individual tap dances
void numpad_finished(tap_dance_state_t *state, void *user_data);
void numpad_reset(tap_dance_state_t *state, void *user_data);
void scape_finished(tap_dance_state_t *state, void *user_data);
void scape_reset(tap_dance_state_t *state, void *user_data);
void play_finished(tap_dance_state_t *state, void *user_data);
void capslock_finished(tap_dance_state_t *state, void *user_data);
void capslock_reset(tap_dance_state_t *state, void *user_data);
void dance_exclam_finished(tap_dance_state_t *state, void *user_data);
void dance_exclam_reset(tap_dance_state_t *state, void *user_data);
void vold_finished(tap_dance_state_t *state, void *user_data);
void vold_reset(tap_dance_state_t *state, void *user_data);
void volu_finished(tap_dance_state_t *state, void *user_data);
void volu_reset(tap_dance_state_t *state, void *user_data);
void lctl_finished(tap_dance_state_t *state, void *user_data);
void lctl_reset(tap_dance_state_t *state, void *user_data);
void functionkeys_finished(tap_dance_state_t *state, void *user_data);
void functionkeys_reset(tap_dance_state_t *state, void *user_data);
void tab_finished(tap_dance_state_t *state, void *user_data);
void tab_reset(tap_dance_state_t *state, void *user_data);
void sftmov_finished(tap_dance_state_t *state, void *user_data);
void sftmov_reset(tap_dance_state_t *state, void *user_data);
void ctlmov_finished(tap_dance_state_t *state, void *user_data);
void ctlmov_reset(tap_dance_state_t *state, void *user_data);
void lprn_finished(tap_dance_state_t *state, void *user_data);
void lprn_reset(tap_dance_state_t *state, void *user_data);
void rprn_finished(tap_dance_state_t *state, void *user_data);
void rprn_reset(tap_dance_state_t *state, void *user_data);
void space_finished(tap_dance_state_t *state, void *user_data);
void space_reset(tap_dance_state_t *state, void *user_data);



// Tap Dance DEFINICIONES
tap_dance_action_t tap_dance_actions[] = {

	[TD_SIFT_CAPSLOCK]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, capslock_finished, capslock_reset),
	[TD_RHAND_LAYER] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, numpad_finished, numpad_reset),
	[TD_WIN_MENU]  = ACTION_TAP_DANCE_DOUBLE(KC_LGUI, KC_APP),
	[TD_MNXT]  = ACTION_TAP_DANCE_DOUBLE(KC_MPLY, KC_MNXT),
	[TD_PLAY]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, play_finished, NULL),
	[TD_ESC] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, scape_finished, scape_reset),	
	[TD_VOLD] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, vold_finished, vold_reset),
	[TD_VOLU] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, volu_finished, volu_reset),
	[TD_TAB]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, tab_finished, tab_reset),
	[TD_SFT_MOV]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, sftmov_finished, sftmov_reset),
	[TD_CTL_MOV]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ctlmov_finished, ctlmov_reset),
	[TD_LPRN]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, lprn_finished, lprn_reset),
	[TD_RPRN]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, rprn_finished, rprn_reset),   
	[TD_SPACE]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, space_finished, space_reset) 
};







// Determine the current tap dance state
td_state_t cur_dance(tap_dance_state_t *state) {
    
    if (state->count == 1) {
        if (!state->pressed) return TD_SINGLE_TAP;
        else return TD_SINGLE_HOLD;	
    } 
    
    else if (state->count == 2) {
    	if (!state->pressed) return TD_DOUBLE_TAP;
    	else return TD_DOUBLE_HOLD;	
    } 
    
    else if (state->count == 3) {
    	if (!state->pressed) return TD_TRIPLE_TAP;
    	else return TD_TRIPLE_HOLD;	
    }
    
    else return TD_UNKNOWN;
    
}

// Initialize tap structure associated with example tap dance key
static td_tap_t numpad_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};




void numpad_finished(tap_dance_state_t *state, void *user_data) {
    
    numpad_tap_state.state = cur_dance(state);
    
    switch (numpad_tap_state.state) {
       
		case TD_SINGLE_TAP:
			
			layer_move(_QWERTY);
			
			if (host_keyboard_led_state().caps_lock) {
				tap_code(KC_CAPS);
			}				
			
			break;
			
			        
		case TD_DOUBLE_TAP:
			
			if (layer_state_is(_QWERTY)) {
				layer_move(_NUM_PAD);
			}   

			else if (layer_state_is(_NUM_PAD)) {
				layer_move(_RNUM_PAD);
			} 
			
			else {
				layer_move(_QWERTY);
			}    		
			
			break;

		
		case TD_SINGLE_HOLD:
			
			layer_on(_NUM_PAD);
			break;

		case TD_DOUBLE_HOLD:
			
			layer_on(_RNUM_PAD);
			
			if (!(host_keyboard_led_state().num_lock)) {
				tap_code(KC_NUM);
			}
			
			break;

		default:
			break;
		
    }
}


void numpad_reset(tap_dance_state_t *state, void *user_data) {

    if ((numpad_tap_state.state == TD_SINGLE_HOLD) || (numpad_tap_state.state == TD_DOUBLE_HOLD)) {
		
		layer_clear();
		
	}
	
    numpad_tap_state.state = TD_NONE;
}




void capslock_finished(tap_dance_state_t *state, void *user_data) {
    
    
    numpad_tap_state.state = cur_dance(state);
    
    switch (numpad_tap_state.state) {
 
		case TD_SINGLE_TAP:		
			// One-Shot Shift: UNA sola mayúscula (ideal para swap_hands / mirror typing)
			// Se consume en la siguiente tecla y se desactiva automáticamente.
			add_oneshot_mods(MOD_LSFT);

			break;
			
        case TD_DOUBLE_TAP:
			// Caps Lock "real" si lo necesitas puntualmente
			tap_code(KC_CAPS);
			
            break;
		
        case TD_SINGLE_HOLD:
			// Shift mantenido mientras sostienes la tecla
			register_code(KC_LSFT);
			
            break;
        
        default:
            break;
    }
}


void capslock_reset(tap_dance_state_t *state, void *user_data) {
	// Solo tiene efecto si venimos de TD_SINGLE_HOLD
	unregister_code(KC_LSFT);
    numpad_tap_state.state = TD_NONE;
    
}




void scape_finished(tap_dance_state_t *state, void *user_data) {
    
    numpad_tap_state.state = cur_dance(state);
    
	switch (numpad_tap_state.state) {
		
		case TD_SINGLE_TAP:
				
			tap_code(KC_ESC);


			if (host_keyboard_led_state().caps_lock) {
				
				tap_code(KC_CAPS);
			}

			break;

		case TD_SINGLE_HOLD:
			
			register_code16(KC_LCTL);
            layer_on(_QWERTY2);
			
			break;

		case TD_DOUBLE_TAP:
			
			tap_code(KC_ESC);
			tap_code(KC_ESC);
			break;
				  
		case TD_DOUBLE_HOLD:
			
			register_code16(KC_ESC);
			
			break;

		default:
			break;
	}
}


void scape_reset(tap_dance_state_t *state, void *user_data) {
		
		unregister_code16(KC_LCTL);
		unregister_code16(KC_ESC);
        layer_off(_QWERTY2);
        layer_clear();
		numpad_tap_state.state = TD_NONE;
		
}

void vold_finished(tap_dance_state_t *state, void *user_data) {
    
    numpad_tap_state.state = cur_dance(state);
    
    switch (numpad_tap_state.state) {
        
        case TD_SINGLE_TAP:
			
			register_code16(KC_VOLD);
            break;
        
        case TD_SINGLE_HOLD:
        	
        	tap_code(KC_MNXT);
            break;
        
        case TD_DOUBLE_HOLD:
        	
        	register_code16(KC_VOLD);
            break;
        
        case TD_DOUBLE_TAP:
    		
    		SEND_STRING(SS_TAP(X_VOLD) SS_TAP(X_VOLD));
        	break;            
        
        case TD_TRIPLE_TAP:
    		
    		SEND_STRING(SS_TAP(X_VOLD) SS_TAP(X_VOLD) SS_TAP(X_VOLD));
        	break;
        
        default:
        	break;
    }
}


void vold_reset(tap_dance_state_t *state, void *user_data) {
    
    if (state->count == 1) {
        
        unregister_code16(KC_VOLD);
    }
    
    numpad_tap_state.state = TD_NONE;
    
}





void volu_finished(tap_dance_state_t *state, void *user_data) {
    
    numpad_tap_state.state = cur_dance(state);
    
    switch (numpad_tap_state.state) {
        
        case TD_SINGLE_TAP:
			
			register_code16(KC_VOLU);
            break;
       
        case TD_SINGLE_HOLD:
        	
        	tap_code(KC_MPRV);
            break;
        
        case TD_DOUBLE_TAP:
    		
    		SEND_STRING(SS_TAP(X_VOLU) SS_TAP(X_VOLU));
        	break; 
        
        case TD_DOUBLE_HOLD:
        	
        	register_code16(KC_VOLU);
            break;           
        
        case TD_TRIPLE_TAP:
    		
    		SEND_STRING(SS_TAP(X_VOLU) SS_TAP(X_VOLU) SS_TAP(X_VOLU));
        	break;
        	
        default:
            break;
    }
}


void volu_reset(tap_dance_state_t *state, void *user_data) {

    unregister_code16(KC_VOLU);
    
    numpad_tap_state.state = TD_NONE;
    
}





void play_finished(tap_dance_state_t *state, void *user_data) {
    
    numpad_tap_state.state = cur_dance(state);
    
    switch (numpad_tap_state.state) {
        
        case TD_SINGLE_TAP:
			
			tap_code(KC_MPLY);
            break;
        
        case TD_DOUBLE_TAP:
        	
        	tap_code(KC_MUTE);
            break;
        
        default:
            break;
    }
    
}


void play_reset(tap_dance_state_t *state, void *user_data) {
	
	numpad_tap_state.state = TD_NONE;
	
}




void tab_finished(tap_dance_state_t *state, void *user_data) {
    
    numpad_tap_state.state = cur_dance(state);
    
    switch (numpad_tap_state.state) {
        
		case TD_SINGLE_TAP:
			
			tap_code(KC_TAB);   		
			
			break;

		
		case TD_SINGLE_HOLD:
			
			layer_on(_LOWER);
			break;

			
		case TD_DOUBLE_HOLD:
			
			layer_on(_FUNCTION_KEYS);
			
			break;

		case TD_TRIPLE_HOLD:
			
			layer_on(_FUNCTION2_KEYS);
			
			break;
			
		default:
			break;
		
    }
}


void tab_reset(tap_dance_state_t *state, void *user_data) {

	layer_clear();
    numpad_tap_state.state = TD_NONE;
    
}




void sftmov_finished(tap_dance_state_t *state, void *user_data) {
    
    numpad_tap_state.state = cur_dance(state);
    
    switch (numpad_tap_state.state) {
        
		case TD_SINGLE_TAP:
			
			tap_code(KC_V);  		
			break;

		
		case TD_SINGLE_HOLD:
			
			layer_on(_MOV);
			register_code16(KC_LSFT);
			
			break;

			
		case TD_DOUBLE_TAP:
			
			tap_code(KC_V);
			tap_code(KC_V);
			break;

		case TD_DOUBLE_HOLD:
			
			register_code16(KC_V);
			
			break;

		default:
			break;
		
    }
}


void sftmov_reset(tap_dance_state_t *state, void *user_data) {


	unregister_code16(KC_V);
	unregister_code16(KC_LSFT);
	layer_clear();
	
    numpad_tap_state.state = TD_NONE;
}



void ctlmov_finished(tap_dance_state_t *state, void *user_data) {
    
    numpad_tap_state.state = cur_dance(state);
    
    switch (numpad_tap_state.state) {
        
		case TD_SINGLE_TAP:
			
			tap_code(KC_C);  		
			break;

		
		case TD_SINGLE_HOLD:
			
			layer_on(_MOV);
			register_code16(KC_LCTL);
			break;

			
		case TD_DOUBLE_TAP:
			
			tap_code(KC_C);
			tap_code(KC_C);
			break;

		case TD_DOUBLE_HOLD:
			
			register_code16(KC_C);
			
			break;

		default:
			break;
		
    }
}


void ctlmov_reset(tap_dance_state_t *state, void *user_data) {

    if ((numpad_tap_state.state == TD_SINGLE_HOLD) || (numpad_tap_state.state == TD_DOUBLE_HOLD)) {
		
		unregister_code16(KC_C);
		unregister_code16(KC_LCTL);
		layer_clear();
		
		
	}

    numpad_tap_state.state = TD_NONE;
}




void lprn_finished(tap_dance_state_t *state, void *user_data) {
    
    numpad_tap_state.state = cur_dance(state);
 
    switch (numpad_tap_state.state) {
        
		case TD_SINGLE_TAP:
			
			SEND_STRING("(");		
			break;

		
		case TD_SINGLE_HOLD:
			
			SEND_STRING("{");
			break;

		case TD_DOUBLE_TAP:
			
			SEND_STRING("[");		
			break;
						
		default:
			break;
		
    }
}


void lprn_reset(tap_dance_state_t *state, void *user_data) {

    numpad_tap_state.state = TD_NONE;
}




void rprn_finished(tap_dance_state_t *state, void *user_data) {
    
    numpad_tap_state.state = cur_dance(state);
 
    switch (numpad_tap_state.state) {
        
		case TD_SINGLE_TAP:
			
			SEND_STRING(")");		
			break;

		
		case TD_SINGLE_HOLD:
			
			SEND_STRING("}");
			break;

		case TD_DOUBLE_TAP:
			
			SEND_STRING("]");		
			break;
						
		default:
			break;
		
    }

}



void rprn_reset(tap_dance_state_t *state, void *user_data) {

    numpad_tap_state.state = TD_NONE;
}


void space_finished(tap_dance_state_t *state, void *user_data) {
    
    numpad_tap_state.state = cur_dance(state);

    switch (numpad_tap_state.state) {
        
		case TD_SINGLE_TAP:
			
			tap_code(KC_SPACE); 		
			break;

		
		case TD_SINGLE_HOLD:
			
			swap_hands_on();
			break;

			
		case TD_DOUBLE_TAP:
			
			//layer_on(_I3);
			break;

		case TD_DOUBLE_HOLD:
			
			layer_on(_I3);
	
			break;

		default:
			break;
		
    }
}

void space_reset(tap_dance_state_t *state, void *user_data) {

    if (numpad_tap_state.state == TD_SINGLE_HOLD) {
		
		swap_hands_off();
		
	}

    if (numpad_tap_state.state == TD_DOUBLE_HOLD) {
		
		layer_off(_I3);
		
	}
		
    numpad_tap_state.state = TD_NONE;
}


void running_boot(void){

	if (timer_elapsed32(key_timer_boot) > tiempo_boot) {
	
	key_timer_boot = timer_read32();
		if(is_boot_active){
		  //SEND_STRING(SS_TAP(X_F13));
		  // SEND_STRING(SS_TAP(X_WH_U)); //Rueda del ratón hacia arriba
		  // SEND_STRING(SS_TAP(X_WH_D)); //Rueda del ratón hacia abajo
		  SEND_STRING(SS_TAP(X_MS_U)); //Mueve el ratón hacia arriba
		  SEND_STRING(SS_TAP(X_MS_D)); //Mueve el ratón hacia abajo
		  SEND_STRING(SS_TAP(X_MS_R)); //Mueve el ratón hacia derecha
		  SEND_STRING(SS_TAP(X_MS_L)); //Mueve el ratón hacia izquierda
		  // SEND_STRING(SS_TAP(X_BTN1)); //Pulsa el botón 1 del ratón
		  // SEND_STRING(SS_TAP(X_BTN2)); //Pulsa el botón 2 del ratón
		  // SEND_STRING(SS_TAP(X_BTN3)); //Pulsa el botón 3 del ratón
		}
	}
	
}	


void handleBoot(){
	
	is_boot_active = !is_boot_active;
	
	if(is_boot_active){
		
		tiempo_boot = 600000; //10 minutos
		SEND_STRING("Boot Actived\n");
	}
	else{


		tiempo_boot = 0;
		SEND_STRING("Boot Unactived\n");
	}  
}

void matrix_scan_user(void) {
	// Alt-Tab / Win-Tab: auto-release por timeout
	if (alttab_active && timer_elapsed(alttab_timer) > MODTAB_TIMEOUT_MS) {
		unregister_code(KC_LALT);
		alttab_active = false;
	}
	if (wintab_active && timer_elapsed(wintab_timer) > MODTAB_TIMEOUT_MS) {
		unregister_code(KC_LGUI);
		wintab_active = false;
	}

	running_boot();
		
}


uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case RGUI_T(KC_Q):
		case RALT_T(KC_W):
		case RCTL_T(KC_E):
		case LT(_MOUSE,KC_T):
		case RCTL_T(KC_I):
		case RALT_T(KC_O):
		case RGUI_T(KC_P):
		case LT(_MOV,KC_A):
		case LALT_T(KC_S):
		case LCTL_T(KC_D):
		case LT(_MOV2,KC_G):
		case LCTL_T(KC_K):
		case LALT_T(KC_L):
		case LT(_FUNCTION_KEYS,KC_SCLN):
		case LT(_FUNCTION2_KEYS,KC_QUOT):
		case LGUI_T(KC_Z):
		
			return TAPPING_TERM + 100;
		
		case KC_LSFT:
		case KC_RSFT:
		case SH_T(KC_SPACE):
		
			return TAPPING_TERM - 50;
			
        default:
            return TAPPING_TERM;
    }
}

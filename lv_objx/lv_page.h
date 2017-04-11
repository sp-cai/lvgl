/**
 * @file lv_page.h
 * 
 */

#ifndef LV_PAGE_H
#define LV_PAGE_H

/*********************
 *      INCLUDES
 *********************/
#include "lv_conf.h"
#if USE_LV_PAGE != 0

/*Testing of dependencies*/
#if USE_LV_RECT == 0
#error "lv_page: lv_rect is required. Enable it in lv_conf.h (USE_LV_RECT  1) "
#endif

#include "../lv_obj/lv_obj.h"
#include "lv_rect.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/*Data of page*/
typedef struct
{
    lv_rect_ext_t bg_rect; /*Ext. of ancestor*/
    /*New data for this type */
    lv_obj_t * scrl;            /*The scrollable object on the background*/
    lv_action_t rel_action;     /*Function to call when the page is released*/
    lv_action_t pr_action;      /*Function to call when the page is pressed*/
    area_t sbh;                 /*Horizontal scrollbar area relative to the page. (Handled by the library) */
    area_t sbv;                 /*Vertical scrollbar area relative to the page (Handled by the library)*/
    uint8_t sbh_draw :1;        /*1: horizontal scrollbar is visible now (Handled by the library)*/
    uint8_t sbv_draw :1;        /*1: vertical scrollbar is visible now (Handled by the library)*/
}lv_page_ext_t;

/*Scrollbar modes: shows when should the scrollbars be visible*/
typedef enum
{
	LV_PAGE_SB_MODE_OFF,    /*Never show scrollbars*/
	LV_PAGE_SB_MODE_ON,     /*Always show scrollbars*/
	LV_PAGE_SB_MODE_DRAG,   /*Show scrollbars when page is being dragged*/
    LV_PAGE_SB_MODE_AUTO,   /*Show scrollbars when the scrollable rect. is large enough to be scrolled*/
}lv_page_sb_mode_t;

/*Style of page*/
typedef struct
{
    lv_rects_t bg;                  /*Style of ancestor*/
	/*New style element for this type */
    lv_rects_t scrl;                /*Style of the scrollable rectangle*/
    lv_rects_t sb;                  /*Style of scrollbars*/
    cord_t sb_width;                /*Width of the scrollbars*/
    lv_page_sb_mode_t sb_mode;      /*Scrollbar visibility from 'lv_page_sb_mode_t'*/
}lv_pages_t;

/*Built-in styles of page*/
typedef enum
{
    LV_PAGES_DEF,
    LV_PAGES_PAPER,                 /*White background, transparent scrollable*/
    LV_PAGES_MENU,                  /*Transparent background, gray scrollable*/
	LV_PAGES_TRANSP,
}lv_pages_builtin_t;

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/**
 * Create a page objects
 * @param par pointer to an object, it will be the parent of the new page
 * @param copy pointer to a page object, if not NULL then the new object will be copied from it
 * @return pointer to the created page
 */
lv_obj_t * lv_page_create(lv_obj_t * par, lv_obj_t * copy);

/**
 * Signal function of the page
 * @param page pointer to a page object
 * @param sign a signal type from lv_signal_t enum
 * @param param pointer to a signal specific variable
 */
bool lv_page_signal(lv_obj_t * page, lv_signal_t sign, void * param);

/**
 * Set a release action for the page
 * @param page pointer to a page object
 * @param rel_action a function to call when the page is released
 */
void lv_page_set_rel_action(lv_obj_t * page, lv_action_t rel_action);

/**
 * Set a press action for the page
 * @param page pointer to a page object
 * @param pr_action a function to call when the page is pressed
 */
void lv_page_set_pr_action(lv_obj_t * page, lv_action_t pr_action);

/**
 * Glue the object to the page. After it the page can be moved (dragged) with this object too.
 * @param obj pointer to an object on a page
 * @param glue true: enable glue, false: disable glue
 */
void lv_page_glue_obj(lv_obj_t * obj, bool glue);

/**
 * Focus on an object. It ensures that the object will be visible on the page.
 * @param page pointer to a page object
 * @param obj pointer to an object to focus (must be on the page)
 * @param anim_en true: scroll with animation
 */
void lv_page_focus(lv_obj_t * page, lv_obj_t * obj, bool anim_en);

/**
 * Get the scrollable object of a page-
 * @param page pointer to page object
 * @return pointer to rectangle which is the scrollable part of the page
 */
lv_obj_t * lv_page_get_scrl(lv_obj_t * page);

/**
 * Return with a pointer to a built-in style and/or copy it to a variable
 * @param style a style name from lv_pages_builtin_t enum
 * @param copy copy the style to this variable. (NULL if unused)
 * @return pointer to an lv_pages_t style
 */
lv_pages_t * lv_pages_get(lv_pages_builtin_t style, lv_pages_t * copy);

/**********************
 *      MACROS
 **********************/

#endif

#endif

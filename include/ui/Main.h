#ifndef MAIN_H
#define MAIN_H
#include <Server.h>
#include <cJSON.h>
#include <ui/Components.h>

void ui_update_playerlist(Server* server);

bool ui_update_delete(struct _Component* component);

bool ui_button_op(struct _Component* component);
bool ui_button_kick(struct _Component* component);
bool ui_button_ban(struct _Component* component);

#endif
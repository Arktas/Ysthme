#include "Hitbox.h"

Hitbox::Hitbox()
{
}

Hitbox::~Hitbox()
{
}

int Hitbox::check(int Xmin,int Ymin,int Xmax, int Ymax, int type)
{
    std::list<Info_position>::iterator it;
    for(it=info_list.begin();it!=info_list.end();it++)
    {
        if(Xmin>=it->Xmin && Xmin<=it->Xmax || Xmax>=it->Xmin && Xmax<=it->Xmax)
        {
            if(Ymin>=it->Ymin && Ymin<=it->Ymax || Ymax>=it->Ymin && Ymax<=it->Ymax)
            {
                switch(type)
                {
                    case _H_MONSTER :
                        switch(it->type)
                        {
                            case _H_ENVIRONMENT :
                                return _H_WALL;
                            break;
                            case _H_ENVIRONMENT_T :
                                return _H_NOTHING;
                            break;
                            case _H_MONSTER :
                                return _H_WALL;
                            break;
                            case _H_CHARACTER :
                                return _H_WALL;
                            break;
                            case _H_PLAYER :
                                return _H_WALL;
                            break;
                            case _H_PROJECTILE_PLAYER :
                                return _H_HIT;
                            break;
                            case _H_PROJECTILE_MONSTER :
                                return _H_NOTHING;
                            break;
                            case _H_ITEM :
                                return _H_NOTHING;
                            break;
                        }
                    break;
                    case _H_CHARACTER :
                        switch(it->type)
                        {
                            case _H_ENVIRONMENT :
                                return _H_WALL;
                            break;
                            case _H_ENVIRONMENT_T :
                                return _H_NOTHING;
                            break;
                            case _H_MONSTER :
                                return _H_WALL;
                            break;
                            case _H_CHARACTER :
                                return _H_WALL;
                            break;
                            case _H_PLAYER :
                                return _H_WALL;
                            break;
                            case _H_PROJECTILE_PLAYER :
                                return _H_NOTHING;
                            break;
                            case _H_PROJECTILE_MONSTER :
                                return _H_HIT;
                            break;
                            case _H_ITEM :
                                return _H_NOTHING;
                            break;
                        }
                    break;
                    case _H_PLAYER :
                        switch(it->type)
                        {
                            case _H_ENVIRONMENT :
                                return _H_WALL;
                            break;
                            case _H_ENVIRONMENT_T :
                                return _H_NOTHING;
                            break;
                            case _H_MONSTER :
                                return _H_WALL;
                            break;
                            case _H_CHARACTER :
                                return _H_WALL;
                            break;
                            case _H_PLAYER :
                                return _H_WALL;
                            break;
                            case _H_PROJECTILE_PLAYER :
                                return _H_NOTHING;
                            break;
                            case _H_PROJECTILE_MONSTER :
                                return _H_NOTHING;
                            break;
                            case _H_ITEM :
                                return _H_DROP;
                            break;
                        }
                    break;
                    case _H_PROJECTILE_PLAYER :
                        switch(it->type)
                        {
                            case _H_ENVIRONMENT :
                                return _H_WALL;
                            break;
                            case _H_ENVIRONMENT_T :
                                return _H_NOTHING;
                            break;
                            case _H_MONSTER :
                                return _H_HIT;
                            break;
                            case _H_CHARACTER :
                                return _H_NOTHING;
                            break;
                            case _H_PLAYER :
                                return _H_NOTHING;
                            break;
                            case _H_PROJECTILE_PLAYER :
                                return _H_NOTHING;
                            break;
                            case _H_PROJECTILE_MONSTER :
                                return _H_NOTHING;
                            break;
                            case _H_ITEM :
                                return _H_NOTHING;
                            break;
                        }
                    break;
                    case _H_PROJECTILE_MONSTER:
                        switch(it->type)
                        {
                            case _H_ENVIRONMENT :
                                return _H_WALL;
                            break;
                            case _H_ENVIRONMENT_T :
                                return _H_NOTHING;
                            break;
                            case _H_MONSTER :
                                return _H_NOTHING;
                            break;
                            case _H_CHARACTER :
                                return _H_HIT;
                            break;
                            case _H_PLAYER :
                                return _H_HIT;
                            break;
                            case _H_PROJECTILE_PLAYER :
                                return _H_NOTHING;
                            break;
                            case _H_PROJECTILE_MONSTER :
                                return _H_NOTHING;
                            break;
                            case _H_ITEM :
                                return _H_NOTHING;
                            break;
                        }
                    break;
                }
            }
        }
    }
}

void Hitbox::save(int Xmin,int Ymin,int Xmax, int Ymax,int type)
{
    Info_position temp;
    temp.Xmin = Xmin;
    temp.Ymin = Ymin;
    temp.Xmax = Xmax;
    temp.Ymax = Ymax;
    temp.type = type;
    info_list_temp.push_back(temp);
}

void Hitbox::reset()
{
    info_list.clear();
    std::list<Info_position>::iterator it;
    for(it=info_list_temp.begin();it!=info_list_temp.end();it++)
    {
        Info_position temp;
        temp.Xmin = it->Xmin;
        temp.Ymin = it->Ymin;
        temp.Xmax = it->Xmax;
        temp.Ymax = it->Ymax;
        temp.type = it->type;
        info_list.push_back(temp);
    }
    info_list_temp.clear();
}

/*
 * Copyright (C) 2013-2015 DeathCore <http://www.noffearrdeathproject.net/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "siege_of_the_niuzoa_temple.h"

class instance_siege_of_the_niuzoa_temple : public InstanceMapScript
{
public:
    instance_siege_of_the_niuzoa_temple() : InstanceMapScript("instance_siege_of_the_niuzoa_temple", 1011) { }

    InstanceScript* GetInstanceScript(InstanceMap* map) const
    {
        return new instance_siege_of_the_niuzoa_temple_InstanceMapScript(map);
    }

    struct instance_siege_of_the_niuzoa_temple_InstanceMapScript : public InstanceScript
    {
        uint64 jinbakGuid;
        uint64 vojakGuid;
        uint64 pavalakGuid;
        uint64 neronokGuid;

        instance_siege_of_the_niuzoa_temple_InstanceMapScript(Map* map) : InstanceScript(map)
        {}

        void Initialize()
        {
            jinbakGuid  = 0;
            vojakGuid   = 0;
            pavalakGuid = 0;
            neronokGuid = 0;
        }

        void OnCreatureCreate(Creature* creature)
        {
            switch (creature->GetEntry())
            {
                case NPC_JINBAK:
                    jinbakGuid = creature->GetGUID();
                    break;
                case NPC_VOJAK:
                    vojakGuid = creature->GetGUID();
                    break;
                case NPC_PAVALAK:
                    pavalakGuid = creature->GetGUID();
                    break;
                case NPC_NERONOK:
                    neronokGuid = creature->GetGUID();
                    break;
            }
        }

        void OnGameObjectCreate(GameObject* go)
        {
        }

        void SetData(uint32 type, uint32 data)
        {}

        uint32 GetData(uint32 type)
        {
            return 0;
        }

        uint64 GetData64(uint32 type)
        {
            switch (type)
            {
                case NPC_JINBAK:    return jinbakGuid;
                case NPC_VOJAK:     return vojakGuid;
                case NPC_PAVALAK:   return pavalakGuid;
                case NPC_NERONOK:   return neronokGuid;
            }

            return 0;
        }
    };

};

void AddSC_instance_siege_of_the_niuzoa_temple()
{
    new instance_siege_of_the_niuzoa_temple();
}

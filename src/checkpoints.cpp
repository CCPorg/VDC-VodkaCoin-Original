// Copyright (c) 2009-2012 The Bitcoin developers
// Copyright (c) 2011-2012 Litecoin Developers
// Copyright (c) 2013 Elephancoin Developers
// Copyright (c) 2014 VodkaCoin Developer
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <boost/assign/list_of.hpp> // for 'map_list_of()'
#include <boost/foreach.hpp>

#include "checkpoints.h"

#include "main.h"
#include "uint256.h"

namespace Checkpoints
{
    typedef std::map<int, uint256> MapCheckpoints;

	// no checkpoint now, can be added in later releases
    static MapCheckpoints mapCheckpoints =
            boost::assign::map_list_of
(0,      uint256("0xb66fb00529ed533356f3098389011fc55b95340e81c62e6d62238b40aac83ffd"))
(25,     uint256("0x09d9c91f84f2e8bedea5b2e932bb28a8d0103adc22fa971bb9eaced6525c5ac0"))
(135,    uint256("0x7e2be6310f18486785aae6cccfcedf78fc6fe0097be26da4be9aa7d595ae5732"))
(768,    uint256("0xc0e2698871f6abb81297b662ca80fa40c21cb8795870fa61f75d8a13e443a68d"))
(1275,   uint256("0x5dac34647e3f92ba1fad5ddf35f0e9df16579b4b80b851d09ee8dfc229129e13"))
(27499,  uint256("0x213ea83fbcdea7d720d09acc7a281551c4b750062de5616edda7fa5b573a64b6"))
(54935,  uint256("0xe169b340194745b3677c952128468f16433235813a481cf3c432b2d7c025478f"))
(98342,  uint256("0x0975f2af4db5c0fa1610edc4f21a79a79621aec5cf9edb7e8665934aad009971"))
(145390, uint256("0xf00d2b3094c88f580a5dca82059f896444329ca9574c0732ce7a59d945498aa2"))
(187404, uint256("0x3c05796fe8d79eb62feab47d13b9c801531416d62588061e41baea6b84b828b8"))
(227452, uint256("0xdc6c48d51e40cfeea8c71d67d8da7d680b377e8490dc52104918e9a188ca5eb8"))
(259745, uint256("0x04600f377042fd859f2a2dc3292fa8ab066b71044287dc5bf1c553a20a1e6359"))
(284035, uint256("0xb95061fb29a54410935d5224c1096ccc7d2962c9fda53b3c782f7d903a53a6a2"))
(326824, uint256("0x46fc28babf65703583890b63cf7883f6352a33db99843134c13bcf3f33c2aa21"))
(363893, uint256("0x0aa6193b77ad48064a28acd4c4441048701d36cf613f767bb326b86d8cc15dda"))
(418454, uint256("0x7f186a20d27f4f88fc910034cecd9477f5e0204a3fe6766ab32b47b3f7e9a761"))
(478093, uint256("0x1ad1ae1e4f415046cfaddfda98aaebc57ffd117edc66c3bc5a39478e27a6ac3c"))
;


    bool CheckBlock(int nHeight, const uint256& hash)
    {
        if (fTestNet) return true; // Testnet has no checkpoints

        MapCheckpoints::const_iterator i = mapCheckpoints.find(nHeight);
        if (i == mapCheckpoints.end()) return true;

//### Default Value
return hash == i->second;

//### Produce Value
//return true;
    }

    int GetTotalBlocksEstimate()
    {
        if (fTestNet) return 0;

//### Default Value
return mapCheckpoints.rbegin()->first;

//### Produce Value
//return 0;
    }

    CBlockIndex* GetLastCheckpoint(const std::map<uint256, CBlockIndex*>& mapBlockIndex)
    {
        if (fTestNet) return NULL;

        BOOST_REVERSE_FOREACH(const MapCheckpoints::value_type& i, mapCheckpoints)
        {
            const uint256& hash = i.second;
            std::map<uint256, CBlockIndex*>::const_iterator t = mapBlockIndex.find(hash);
            if (t != mapBlockIndex.end())
//### Default Value
return t->second;

//### Produce Value
//return NULL;
        }
        return NULL;
    }
}

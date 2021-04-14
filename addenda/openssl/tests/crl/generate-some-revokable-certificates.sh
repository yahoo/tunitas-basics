#!/bin/sh
source ${0%/*}/rigging.sh || exit 70
cd ${0%/*} || exit 70
set -e
mkdir -p revoke

# This this will become a CA so you'll automatically get critical,CA:TRUE
req ec C=US ST=California L='Palo Alto' O='Newco' OU='Boiler Room' > ca.csr.pem

#          in         out        out
ca --quiet ca.csr.pem ca.key.pem ca.crt.pem
test -e ca.key.pem
test -e ca.crt.pem

declare count=0
function reqcrt() {
    count=$((count+1))
    local csrfile=$(printf "revoke/%02d.csr.pem" $count)
    local crtfile=$(printf "revoke/%02d.crt.pem" $count)
    echo "creating $count $csrfile $crtfile ..."
    req "$@" > ${csrfile?} && crt ca.key.pem ca.crt.pem ${csrfile?} > ${crtfile?}
}

reqcrt ec C=US ST=California L='Santa Clara' O='Special' OU='Waning Sun'
reqcrt ec C=US ST=California L='Santa Clara' O='Special' OU='Red Cleric'
reqcrt ec C=US ST=California L='Santa Clara' O='Special' OU='Space Banjo'

reqcrt ec C=US ST=California L='San Jose' O='Normal' OU='Green Trombone'
reqcrt ec C=US ST=California L='San Jose' O='Normal' OU='Covert General'
reqcrt ec C=US ST=California L='San Jose' O='Normal' OU='Dessert Pickle'

reqcrt ec C=US ST=California L='San Francisco' O='Gruesome' OU='Green Trombone'
reqcrt ec C=US ST=California L='San Francisco' O='Gruesome' OU='Covert General'
reqcrt ec C=US ST=California L='San Francisco' O='Gruesome' OU='Dessert Pickle'

# But will it play in Peoria?
reqcrt ec C=US ST=California L='Lake Tahoe' O='Fantastic' OU='Gruesome Backpack'
reqcrt ec C=US ST=California L='Lake Tahoe' O='Fantastic' OU='Cloudy Screwdriver'
reqcrt ec C=US ST=California L='Lake Tahoe' O='Fantastic' OU='Surreal Rhinestone'
reqcrt ec C=US ST=California L='Lake Tahoe' O='Fantastic' OU='Essential Teal Summer'
reqcrt ec C=US ST=California L='Lake Tahoe' O='Fantastic' OU='Ninth Avenue'
reqcrt ec C=US ST=California L='Lake Tahoe' O='Fantastic' OU='Steamy Cat'
reqcrt ec C=US ST=California L='Lake Tahoe' O='Fantastic' OU='Red Snake'
reqcrt ec C=US ST=California L='Lake Tahoe' O='Fantastic' OU='Massive Kangaroo'
reqcrt ec C=US ST=California L='Lake Tahoe' O='Fantastic' OU='Bitter Electron'
reqcrt ec C=US ST=California L='Lake Tahoe' O='Fantastic' OU='Accidentally Ostrich'
reqcrt ec C=US ST=California L='Lake Tahoe' O='Fantastic' OU='Beta Ghastly'
reqcrt ec C=US ST=California L='Lake Tahoe' O='Fantastic' OU='Steep Weather'
reqcrt ec C=US ST=California L='Lake Tahoe' O='Fantastic' OU='Rough Oyster'
reqcrt ec C=US ST=California L='Lake Tahoe' O='Fantastic' OU='Solid Ostrich'
reqcrt ec C=US ST=California L='Lake Tahoe' O='Fantastic' OU='Forgotten Pottery'
reqcrt ec C=US ST=California L='Lake Tahoe' O='Fantastic' OU='Beta Temporary'
reqcrt ec C=US ST=California L='Lake Tahoe' O='Fantastic' OU='Lucky Zeus'
reqcrt ec C=US ST=California L='Lake Tahoe' O='Fantastic' OU='Green Toupee'
reqcrt ec C=US ST=California L='Lake Tahoe' O='Fantastic' OU='Strawberry Logbook'
reqcrt ec C=US ST=California L='Lake Tahoe' O='Fantastic' OU='Eternal Frostbite'
reqcrt ec C=US ST=California L='Lake Tahoe' O='Fantastic' OU='Gutsy Flag'
reqcrt ec C=US ST=California L='Lake Tahoe' O='Fantastic' OU='Test Moving'
reqcrt ec C=US ST=California L='Lake Tahoe' O='Fantastic' OU='Eyelid Lonesome'
reqcrt ec C=US ST=California L='Lake Tahoe' O='Fantastic' OU='Northernmost Nitrogen'
reqcrt ec C=US ST=California L='Lake Tahoe' O='Fantastic' OU='Magenta Toothbrush'
reqcrt ec C=US ST=California L='Lake Tahoe' O='Fantastic' OU='Steep Railroad'
reqcrt ec C=US ST=California L='Lake Tahoe' O='Fantastic' OU='Boomerang Random'
reqcrt ec C=US ST=California L='Lake Tahoe' O='Fantastic' OU='Eastern Swallow'
reqcrt ec C=US ST=California L='Lake Tahoe' O='Fantastic' OU='Gruesome Beta'
reqcrt ec C=US ST=California L='Lake Tahoe' O='Fantastic' OU='Long Sliding Zeus'
reqcrt ec C=US ST=California L='Lake Tahoe' O='Fantastic' OU='Frozen Street'
reqcrt ec C=US ST=California L='Lake Tahoe' O='Fantastic' OU='Microphone Harsh'
reqcrt ec C=US ST=California L='Lake Tahoe' O='Fantastic' OU='Serious Hurricane'
reqcrt ec C=US ST=California L='Lake Tahoe' O='Fantastic' OU='Teal Kangaroo'
reqcrt ec C=US ST=California L='Lake Tahoe' O='Fantastic' OU='Vital Lantern'
reqcrt ec C=US ST=California L='Lake Tahoe' O='Fantastic' OU='Essential Forsaken Autopsy'
reqcrt ec C=US ST=California L='Lake Tahoe' O='Fantastic' OU='Antique Stormy'
reqcrt ec C=US ST=California L='Lake Tahoe' O='Fantastic' OU='Rocky Haystack'
reqcrt ec C=US ST=California L='Lake Tahoe' O='Fantastic' OU='Furious Viper'
reqcrt ec C=US ST=California L='Lake Tahoe' O='Fantastic' OU='Blue Zeus'
reqcrt ec C=US ST=California L='Lake Tahoe' O='Fantastic' OU='Aberrant Tire'
reqcrt ec C=US ST=California L='Lake Tahoe' O='Fantastic' OU='Forgotten Artificial'
reqcrt ec C=US ST=California L='Lake Tahoe' O='Fantastic' OU='Tuna Boiling'
reqcrt ec C=US ST=California L='Lake Tahoe' O='Fantastic' OU='Python Serious'
reqcrt ec C=US ST=California L='Lake Tahoe' O='Fantastic' OU='Forsaken Steady Xylophone'
reqcrt ec C=US ST=California L='Lake Tahoe' O='Fantastic' OU='Vital Dagger'
reqcrt ec C=US ST=California L='Lake Tahoe' O='Fantastic' OU='Hungry Cat'
reqcrt ec C=US ST=California L='Lake Tahoe' O='Fantastic' OU='Full Butter'
reqcrt ec C=US ST=California L='Lake Tahoe' O='Fantastic' OU='Pink Waffle'
reqcrt ec C=US ST=California L='Lake Tahoe' O='Fantastic' OU='Pointless Laser'
reqcrt ec C=US ST=California L='Lake Tahoe' O='Fantastic' OU='Next Scissors'
reqcrt ec C=US ST=California L='Lake Tahoe' O='Fantastic' OU='Parachute Grotesque'
reqcrt ec C=US ST=California L='Lake Tahoe' O='Fantastic' OU='Tidy Tombstone'
reqcrt ec C=US ST=California L='Lake Tahoe' O='Fantastic' OU='Quality Hurricane'
reqcrt ec C=US ST=California L='Lake Tahoe' O='Fantastic' OU='Endless Tuba'
reqcrt ec C=US ST=California L='Lake Tahoe' O='Fantastic' OU='Red Gloomy Electron'
reqcrt ec C=US ST=California L='Lake Tahoe' O='Fantastic' OU='Dangerous Wrench'
reqcrt ec C=US ST=California L='Lake Tahoe' O='Fantastic' OU='Locomotive Massive'
reqcrt ec C=US ST=California L='Lake Tahoe' O='Fantastic' OU='Alien Long Finger'
reqcrt ec C=US ST=California L='Lake Tahoe' O='Fantastic' OU='Global Third Waffle'
reqcrt ec C=US ST=California L='Lake Tahoe' O='Fantastic' OU='Eastern Gold Arm'
reqcrt ec C=US ST=California L='Lake Tahoe' O='Fantastic' OU='Long Sledgehammer'
reqcrt ec C=US ST=California L='Lake Tahoe' O='Fantastic' OU='Big Toupee'
reqcrt ec C=US ST=California L='Lake Tahoe' O='Fantastic' OU='Orange Gamma'
reqcrt ec C=US ST=California L='Lake Tahoe' O='Fantastic' OU='Magenta Haystack'
reqcrt ec C=US ST=California L='Lake Tahoe' O='Fantastic' OU='Long Pure Sapphire'
reqcrt ec C=US ST=California L='Lake Tahoe' O='Fantastic' OU='Haystack Screaming'
reqcrt ec C=US ST=California L='Lake Tahoe' O='Fantastic' OU='Cheerful Dog'
reqcrt ec C=US ST=California L='Lake Tahoe' O='Fantastic' OU='Gamma Insane'
reqcrt ec C=US ST=California L='Lake Tahoe' O='Fantastic' OU='Dead Itchy Screwdriver'
reqcrt ec C=US ST=California L='Lake Tahoe' O='Fantastic' OU='Green Flannel'
reqcrt ec C=US ST=California L='Lake Tahoe' O='Fantastic' OU='Old Foot'
reqcrt ec C=US ST=California L='Lake Tahoe' O='Fantastic' OU='Harsh Lion'
reqcrt ec C=US ST=California L='Lake Tahoe' O='Fantastic' OU='Brave Sledgehammer'
reqcrt ec C=US ST=California L='Lake Tahoe' O='Fantastic' OU='Quality Winter'
reqcrt ec C=US ST=California L='Lake Tahoe' O='Fantastic' OU='Official Antique'
reqcrt ec C=US ST=California L='Lake Tahoe' O='Fantastic' OU='Viper Massive'
reqcrt ec C=US ST=California L='Lake Tahoe' O='Fantastic' OU='Gold Windshield'
reqcrt ec C=US ST=California L='Lake Tahoe' O='Fantastic' OU='Eastern Breeze'

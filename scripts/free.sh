!/usr/bin/env bash

# Colors
blue=$'\033[0;34m'
cyan=$'\033[1;96m'
reset=$'\033[0;39m'
darkcyan=$'\033[5;6m'

# Show current used space
initial_df=$(df -H . | grep --color=always -E "Size|Used|Avail|Capacity|[0-9]*\.*[0-9]*Mi|[0-9]*\.*[0-9]*Gi|[0-9]+\.*[0-9]+% |$")
echo -e "${darkcyan}Current space:\n${reset}${initial_df}${reset}"
echo -e "${darkcyan}\nHome folder:${reset}"
du -hd1 . 2>/dev/null | sort -h | grep --color=always "[0-9]*\.*[0-9]*M\t\|[0-9]*\.*[0-9]*G\t\|$"
echo ""

rm -rf ~/Library/*.42_cache_bak*
brew cleanup

# Show before/after
echo "\nSpace before:\n${reset}${initial_df}\n\nSpace after:${reset}"
df -h . | grep --color=always -E "Size|Used|Avail|Capacity|[0-9]*\.*[0-9]*Mi|[0-9]*\.*[0-9]*Gi|[0-9]+\.*[0-9]+% |$"

final_used_space=$(df -H . | grep -v 'Filesystem' | awk '{ printf("%f", $3) }')
freed_space=$(printf "%.1f" $(echo "${initial_used_space} - ${final_used_space}" | bc))
echo "\nFreed space: ${cyan}${freed_space}Gi${reset}"
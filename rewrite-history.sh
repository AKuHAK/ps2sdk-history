# python3 -m pip install git-filter-repo
# add to path filter-repo script location
git filter-repo --mailmap .\my-mailmap.txt --force
git stash clear
git fsck --unreachable
git reflog expire --expire-unreachable=now --all && git gc --prune=now
git remote add origin https://github.com/AKuHAK/ps2sdk-history
git push -f --set-upstream origin master

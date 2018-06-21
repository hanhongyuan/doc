#!/bin/bash
set -e

cd "$(dirname "$(readlink -f "$BASH_SOURCE")")"

repo="$1"

if [ -z "$repo" ]; then
	echo >&2 'error: no repo specified'
	cat >&2 <<EOUSAGE
usage: $0 repo [> README.md]
   ie: $0 php > ../php/README.md

   This script generates a stub README to standard out for the specified repo.
EOUSAGE
	exit 1
fi

gitRepo='https://github.com/docker-library/docs'
hubPage="https://registry.hub.docker.com/_/$repo/"

canonicalRepo="https://github.com/docker-library/$repo"
if [ -s "$repo/github-repo" ]; then
	canonicalRepo="$(< "$repo/github-repo")"
fi
canonicalRepo="$(curl -fsSLI -o /dev/null -w '%{url_effective}\n' "$canonicalRepo")" # follow redirects (http://stackoverflow.com/a/3077316/433558)
travisRepo="${canonicalRepo#*://github.com/}"

if [ -f "$repo/deprecated.md" ]; then
	echo '# DEPRECATED'
	echo
	cat "$repo/deprecated.md"
	echo
fi

cat <<EOREADME
# About this Repo

This is the Git repo of the Docker [official image](https://docs.docker.com/docker-hub/official_repos/) for [$repo]($hubPage). See [the Docker Hub page]($hubPage) for the full readme on how to use this Docker image and for information regarding contributing and issues.

The full readme is generated over in [docker-library/docs]($gitRepo), specifically in [docker-library/docs/$repo]($gitRepo/tree/master/$repo).

See a change merged here that doesn't show up on the Docker Hub yet? Check [the "library/$repo" manifest file in the docker-library/official-images repo](https://github.com/docker-library/official-images/blob/master/library/$repo), especially [PRs with the "library/$repo" label on that repo](https://github.com/docker-library/official-images/labels/library%2F$repo). For more information about the official images process, see the [docker-library/official-images readme](https://github.com/docker-library/official-images/blob/master/README.md).
EOREADME

badges=()

n=$'\n'
t=$'\t'

travisImage="https://img.shields.io/travis/$travisRepo/master.svg"
if svg="$(wget -qO- "$travisImage" 2>/dev/null)" && [[ "$svg" != *unknown* ]]; then
	travisLink="https://travis-ci.org/$travisRepo/branches"
	badges+=( "-${t}[Travis CI:  ${n}${t}![build status badge]($travisImage)]($travisLink)" )
fi

# https://www.appveyor.com/docs/status-badges/#badges-for-projects-with-public-repositories-on-github-and-bitbucket
appveyorImage="https://ci.appveyor.com/api/projects/status/github/docker-library/$repo?branch=master&svg=true"
if svg="$(wget -qO- "$appveyorImage" 2>/dev/null)" && [[ "$svg" != *unknown* ]]; then
	appveyorLink="https://ci.appveyor.com/project/docker-library/$repo"
	badges+=( "-${t}[AppVeyor (Windows):  ${n}${t}![build status badge]($appveyorImage)]($appveyorLink)" )
fi

jenkinsImage="https://doi-janky.infosiftr.net/job/update.sh/job/$repo/badge/icon"
if wget -q --spider "$jenkinsImage" &> /dev/null; then
	jenkinsLink="https://doi-janky.infosiftr.net/job/update.sh/job/$repo"
	badges+=( "-${t}[Automated \`update.sh\`:  ${n}${t}![build status badge]($jenkinsImage)]($jenkinsLink)" )
fi

if [ "${#badges[@]}" -gt 0 ]; then
	IFS=$'\n'
	cat <<-EOREADME

		---

		${badges[*]}
	EOREADME
	unset IFS
fi

cat <<EOREADME

<!-- THIS FILE IS GENERATED BY $gitRepo/blob/master/generate-repo-stub-readme.sh -->
EOREADME
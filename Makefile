SHELL := /bin/bash
new:
	@mkdir -p "${dir}"
	@cd "${dir}" && touch Solution.cpp
	@echo "/**" >> "${dir}"/Solution.cpp
	@echo "* Author: Fbin" >> "${dir}"/Solution.cpp
	@echo "* Link:${link}" >> "${dir}"/Solution.cpp
	@echo "* Created at: $(shell date '+%d/%m/%Y')" >> "${dir}"/Solution.cpp
	@echo "*/" >> "${dir}"/Solution.cpp
	@echo "" >> "${dir}"/Solution.cpp
	@echo "#include <bits/stdc++.h>" >> "${dir}"/Solution.cpp
	@echo "using namespace std;" >> "${dir}"/Solution.cpp

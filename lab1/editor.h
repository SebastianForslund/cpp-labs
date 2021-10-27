#ifndef EDITOR_H
#define EDITOR_H

#include <string>

class Editor {
public:
    using size_type = std::string::size_type;
	/* Creates a text editor containing the text t */
	Editor(const std::string& t) : text(t) {}

    /* Get the size of the current contents */
    size_type get_size() const;

	/*
	 * Text[pos] contains a right parentheses. Returns the position of
	 * the corresponding left parentheses, or string::npos if there
	 * is no match.
	 */
	size_type find_left_par(size_type pos) const;

	 // ... functions to edit the text (insert and delete characters)
private:
	std::string text;
};

#endif

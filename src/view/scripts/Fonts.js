.pragma library

var FontFamily = "Arial"

function getFont(_size, _bold, _italic) {
    return Qt.font({family: FontFamily, pointSize: _size, bold: _bold, italic: _italic})
}

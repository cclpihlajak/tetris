# Tetris Game

A classic Tetris game implementation in HTML5, CSS3, and JavaScript. This repository contains two versions of the game:

## Game Versions

### 1. Simple Tetris (`tetris.html`)
A clean, educational implementation of Tetris with all core features:
- **Full game mechanics**: Movement, rotation, collision detection, and piece locking
- **Scoring system**: Points awarded based on lines cleared (100/300/500/800 × level)
- **Level progression**: Increases every 10 lines cleared
- **Dynamic speed**: Game speeds up with each level (minimum 100ms)
- **Pause functionality**: Press P to pause/resume
- **Game over detection**: Restartable game with score tracking
- **Colorful pieces**: 7 unique tetromino colors
- **Modern UI**: Dark theme with score panel

### 2. Advanced Tetris (`qwen.html`)
Full-featured version with additional enhancements:
- All features from Simple Tetris
- **Start screen** with instructions
- **Next piece preview**
- **Ghost piece** showing drop position
- **Enhanced visual effects** and animations
- **Professional gradient styling**

## How to Play

### Controls
- **← →** : Move piece left/right
- **↓** : Soft drop (move down faster)
- **↑** : Rotate piece clockwise
- **Space** : Hard drop (instant drop to bottom)
- **P** : Pause/Resume game

### Objective
- Stack falling tetromino pieces
- Complete horizontal lines to clear them
- Score points and advance levels
- Game ends when pieces stack to the top

### Scoring
- 1 line: 100 points × level
- 2 lines: 300 points × level
- 3 lines: 500 points × level
- 4 lines: 1200 points × level (Tetris!)

### Level System
- Start at Level 1
- Advance one level every 10 lines cleared
- Game speed increases with each level
- Speed caps at 100ms (Level 10+) for playability

## Getting Started

### Play Locally
1. Clone or download this repository
2. Open `tetris.html` or `qwen.html` in any modern web browser
3. Start playing immediately - no build process needed!

### Run Tests
Open `test.html` in a browser to see the comprehensive test suite with:
- Detailed test cases for all features
- Instructions for manual testing
- Comparison between both versions

## Testing

The project includes `test.html` with a complete manual test suite covering:
- ✅ Game initialization
- ✅ Movement controls
- ✅ Rotation mechanics
- ✅ Line clearing
- ✅ Scoring system
- ✅ Level progression
- ✅ Pause functionality
- ✅ Game over detection
- ✅ Restart functionality
- ✅ Visual elements
- ✅ Collision detection

## Technical Details

### Technologies Used
- **HTML5** Canvas for game rendering
- **CSS3** for modern styling and animations
- **Vanilla JavaScript** (ES6+) for game logic
- **requestAnimationFrame** for smooth gameplay

### Browser Compatibility
Works on all modern browsers:
- Chrome/Edge (Recommended)
- Firefox
- Safari
- Opera

### Code Quality
- Clean, readable code structure
- Input validation and error handling
- Commented design decisions
- No external dependencies

## Project Structure
```
tetris/
├── tetris.html    # Simple version (educational)
├── qwen.html      # Advanced version (full-featured)
├── test.html      # Manual test suite
└── README.md      # This file
```

## Features Comparison

| Feature | Simple (tetris.html) | Advanced (qwen.html) |
|---------|---------------------|---------------------|
| Core Gameplay | ✅ | ✅ |
| Scoring & Levels | ✅ | ✅ |
| Pause/Resume | ✅ | ✅ |
| Colorful Pieces | ✅ | ✅ |
| Modern UI | ✅ | ✅ |
| Start Screen | ❌ | ✅ |
| Next Piece Preview | ❌ | ✅ |
| Ghost Piece | ❌ | ✅ |
| Advanced Animations | ❌ | ✅ |

## Development

No build process required! Simply edit the HTML files and refresh your browser.

### Making Changes
1. Open the HTML file in your preferred code editor
2. Modify the embedded CSS (in `<style>` tags) or JavaScript (in `<script>` tags)
3. Save and refresh your browser to see changes

## License

This is an educational project implementing the classic Tetris game mechanics.

## Contributing

Feel free to fork this project and add your own features!

## Acknowledgments

- Original Tetris game concept by Alexey Pajitnov
- Modern implementation with educational focus
- Designed for learning HTML5 Canvas and game development

---

**Enjoy playing Tetris!** 🎮

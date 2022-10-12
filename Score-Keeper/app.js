const p1 = {
	score: 0,
	button: document.querySelector('#p1Button'),
	display: document.querySelector('#p1Display')
};
const p2 = {
	score: 0,
	button: document.querySelector('#p2Button'),
	display: document.querySelector('#p2Display')
};

const resetButton = document.querySelector('#reset');
const winningScoreSelect = document.querySelector('#playto');
let winningScore = winningScoreSelect.value;
let isGameOver = false;
function updateScore(player, opponent) {
	if (!isGameOver) {
		player.score++;
		player.display.textContent = player.score;
		if (player.score == winningScore) {
			isGameOver = true;
			player.display.classList.add('has-text-success');
			opponent.display.classList.add('has-text-danger');
			player.button.disabled = true;
			opponent.button.disabled = true;
		}
	}
}

p1.button.addEventListener('click', function() {
	updateScore(p1, p2);
});
p2.button.addEventListener('click', function() {
	updateScore(p2, p1);
});
winningScoreSelect.addEventListener('change', function() {
	winningScore = parseInt(this.value);
	reset();
});
resetButton.addEventListener('click', reset);
function reset() {
	for (let p of [ p1, p2 ]) {
		p.score = 0;
		p.display.textContent = 0;
		p.display.classList.remove('has-text-success', 'has-text-danger');
		p.button.disabled = false;
	}
	isGameOver = false;
}

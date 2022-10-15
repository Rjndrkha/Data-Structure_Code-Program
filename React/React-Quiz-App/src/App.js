import React, { useState } from 'react';

export default function App() {
	const questions = [
		{
			questionText: 'MS-Word is an example of?',
			answerOptions: [
				{ answerText: 'An operating system', isCorrect: false },
				{ answerText: 'A processing device', isCorrect: false },
				{ answerText: 'Application software', isCorrect: true },
				{ answerText: 'An input device', isCorrect: false },
			],
		},
		{
			questionText: 'Ctrl, Shift and Alt are called ______ keys',
			answerOptions: [
				{ answerText: 'function', isCorrect: false },
				{ answerText: 'modifier', isCorrect: true },
				{ answerText: 'alphanumeric', isCorrect: false },
				{ answerText: ' adjustment', isCorrect: false },
			],
		},
		{
			questionText: '________ is the process of dividing the disk into tracks and sectors',
			answerOptions: [
				{ answerText: 'Formatting', isCorrect: true },
				{ answerText: ' Tracking', isCorrect: false },
				{ answerText: 'Allotting', isCorrect: false },
				{ answerText: 'Crashing', isCorrect: false },
			],
		},
		{
			questionText: 'Junk e-mail is also called',
			answerOptions: [
				{ answerText: 'Sniffer script', isCorrect: false },
				{ answerText: 'Spoof', isCorrect: false },
				{ answerText: 'Spool', isCorrect: false },
				{ answerText: 'Spam', isCorrect: true },
			],
		},
		{
			questionText: 'By default, your documents print in ________ mode',
			answerOptions: [
				{ answerText: 'design', isCorrect: false },
				{ answerText: 'Page Setup', isCorrect: false },
				{ answerText: ' Portrait', isCorrect: true },
				{ answerText: 'Print View', isCorrect: false },
			],
		},
	];

	const [currentQuestion, setCurrentQuestion] = useState(0);

	const [showScore, setShowScore] = useState(false);

	const [score, setScore] = useState(0);

	const handleAnswerButtonClick = (isCorrect) => {
		if(isCorrect===true){
			setScore(score + 1);
		}

		const nextQuestion = currentQuestion + 1;
		if(nextQuestion < questions.length){
			setCurrentQuestion(nextQuestion);
		} else{
			setShowScore(true)
		}
	};

	return (
		<div className='app'>
			{/* HINT: replace "false" with logic to display the 
      score when the user has answered all the questions */}
			{showScore ? (
				<div className='score-section'>You scored {score} out of {questions.length}</div>
			) : (
				<>
					<div className='question-section'>
						<div className='question-count'>
							<span>Question {currentQuestion + 1}</span>/{questions.length}
						</div>
						<div className='question-text'>{questions[currentQuestion].questionText}</div>
					</div>
					<div className='answer-section'>
						{questions[currentQuestion].answerOptions.map((answerOption) => (
							<button onClick={()=> handleAnswerButtonClick(answerOption.isCorrect)}> {answerOption.answerText}</button>
						))}
					</div>
				</>
			)}
		</div>
	);
}
